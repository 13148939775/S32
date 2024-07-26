
#include <unistd.h>

#include <chrono>
#include <iomanip>
#include <string>
#include <fstream>
#include <iostream>
#include <regex>

#include "DMDefine.h"

using namespace hht::datamanager;

#define DEFAULT_BUFFER_SIZE 100 * 1024 * 1024
#define DEFAULT_TIME_BIN_SIZE 500

using Header = StHeader;

void dump_timeline_printer(uint64_t begin, uint64_t end) {
    std::string str;
    str += "|";
    str += std::string((end-begin)/DEFAULT_TIME_BIN_SIZE, '=')
    ;
    str += "|";
    std::cout << std::left << std::setw(100) << str << std::string(20, ' ') << "(total: " << end-begin << " MS, \"=\": " << DEFAULT_TIME_BIN_SIZE << " MS)" << std::endl;
}

class TriggetTimelinePrinter{
public:
    void set_global_begin(uint64_t time) {gbegin=time;}
    void set_global_end(uint64_t time) {gend=time;}
    void set_id(uint64_t time) {id=time; }
    void set_begin(uint64_t time) {begin=time; }
    void set_end(uint64_t time) {end=time; }
    void set_trigger(uint64_t time) {trigger=time; }

    void trigger_timeline_printer() {
        uint64_t pre_dump = 0;
        uint64_t post_dump = 0;
        if(begin<gbegin) {
            pre_dump = gbegin - begin;
        }
        if(end>gend) {
            post_dump = end - gend;
        }
        std::string str = "|";
        str += std::string((begin>gbegin? begin-gbegin : 0)/DEFAULT_TIME_BIN_SIZE, ' ');
        str += "<";
        str += std::string((trigger - begin)/DEFAULT_TIME_BIN_SIZE -1, '=');
        str += "+";
        str += std::string((end - trigger)/DEFAULT_TIME_BIN_SIZE -1, '=');
        str += ">";

        if(pre_dump>0 && post_dump>0){
            std::cout << std::left << std::setw(100) << str << std::string(20, ' ') << "(id: " << id << ", Pre: " << pre_dump << "MS, Post: " << post_dump << "MS)" << std::endl;
        }
        else if(pre_dump>0){
            std::cout << std::left << std::setw(100) << str << std::string(20, ' ') << "(id: " << id << ", Pre: " << pre_dump << "MS)" << std::endl;
        }
        else if(post_dump>0){
            std::cout << std::left << std::setw(100) << str << std::string(20, ' ') << "(id: " << id << ", Post: " << post_dump << "MS)" << std::endl;
        }
        else {
            std::cout << std::left << std::setw(100) << str << std::string(20, ' ') << "(id: " << id << ")" << std::endl;
        }
    }

private:
    uint64_t gend{0};
    uint64_t gbegin{0};
    uint64_t id{0};
    uint64_t begin{0};
    uint64_t end{0};
    uint64_t trigger{0};
};

int main(int argc, char *argv[]) {
    if(argc != 3) {
        std::cout << "using: ./DumpFileChecker <data> <cfg>" << std::endl;
        return 0;
    }

    std::string data_file = argv[1];
    std::string cfg_file = argv[2];
    std::cout << "DumpFileChecker: checking " << data_file << "/" << cfg_file << std::endl;
    std::cout << std::endl;

    uint64_t gbegin=0;
    uint64_t gend=0;
    {
        std::ifstream file(data_file, std::ios::binary);

        file.seekg (0, file.end);
        size_t size = file.tellg();
        file.seekg (0, file.beg);

        auto buffer = new uint8_t[DEFAULT_BUFFER_SIZE];

        if (!file.read((char*)buffer, size))
        {
            std::cout << "Read Error" << std::endl;
            return 0;
        }

        size_t read_idx = 0;
        uint64_t begin_time = std::numeric_limits<uint64_t>::max();
        uint64_t end_time = std::numeric_limits<uint64_t>::min();

        while(read_idx < size){
            auto header = *reinterpret_cast<Header*>(buffer + read_idx);
            auto topic_id = header.topicId;
            auto payload_size = header.dataLength;
            auto time_stamp = header.timeStamp;
            begin_time = std::min(begin_time, time_stamp);
            end_time = std::max(end_time, time_stamp);
            read_idx += sizeof(Header) + payload_size;
        }
        dump_timeline_printer(begin_time, end_time);
        delete buffer;

        gbegin = begin_time;
        gend = end_time;
    }

    {
        int counter = 0;
        TriggetTimelinePrinter printer;
        printer.set_global_begin(gbegin);
        printer.set_global_end(gend);

        std::ifstream file(cfg_file);

        std::regex rgx_id(".*Trigger_(\\w+)_[0-9]*");
        std::regex rgx_trigger_time(".*Trigger_[0-9]*_(\\w+)*");
        std::regex rgx_begin_time(".*begin: (\\w+)*");
        std::regex rgx_end_time(".*end: (\\w+)*");

        std::string line;
        while (std::getline(file, line))
        {
            // std::cout << line << std::endl;
            std::smatch match;
            if (std::regex_search(line, match, rgx_id)) {
                printer.set_id(std::stol(match[1]));
                // std::cout << "match: " << match[1] << '\n';
            }

            if (std::regex_search(line, match, rgx_trigger_time)) {
                printer.set_trigger(std::stol(match[1]));
                // std::cout << "match: " << match[1] << '\n';
            }

            if (std::regex_search(line, match, rgx_begin_time)) {
                printer.set_begin(std::stol(match[1]));
                // std::cout << "match: " << match[1] << '\n';
            }
            if (std::regex_search(line, match, rgx_end_time)) {
                printer.set_end(std::stol(match[1]));
                printer.trigger_timeline_printer();
                // std::cout << "match: " << match[1] << '\n';
                counter++;
            }
        }
        std::cout << std::left << std::string(120, ' ') << "(Total: " << counter << ")" << std::endl;

    }
    return 0;
}