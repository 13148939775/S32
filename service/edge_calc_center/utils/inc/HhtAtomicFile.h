#ifndef HHTACTOMICFILE_H
#define HHTACTOMICFILE_H

#include <string>

namespace hht {

class AtomicFile {
public:
    explicit AtomicFile(std::string name);

    std::string read();
    void write(std::string content);

    bool exists() const;
    bool hasBackup() const;
    void remove();

    std::string name() const { return mBaseName; }

private:
    bool existsImpl(std::string name) const;

private:
    std::string mBaseName;
    std::string mBackupName;
};

} // namespace hht

#endif  // HHTACTOMICFILE_H
