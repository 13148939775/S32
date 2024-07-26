
#include "HhtAtomicFile.h"

#include <sys/stat.h>
#include <cstdio>

#include <fstream>
#include <sstream>

namespace HHT {

AtomicFile::AtomicFile(std::string name)
    : mBaseName(name)
    , mBackupName(name + ".bak") {
}

std::string AtomicFile::read() {
    if (existsImpl(mBackupName)) {
        std::rename(mBackupName.c_str(), mBaseName.c_str());
    }

    std::stringstream buffer;
    buffer << std::ifstream(mBaseName.c_str()).rdbuf();

    return buffer.str();
}

void AtomicFile::write(std::string content) {
    if (existsImpl(mBaseName) && !existsImpl(mBackupName)) {
        std::rename(mBaseName.c_str(), mBackupName.c_str());
    }

    std::ofstream outfile(mBaseName.c_str());
    outfile << content;
    outfile.close();

    std::remove(mBackupName.c_str());
}

bool AtomicFile::exists() const {
    return existsImpl(mBaseName) || existsImpl(mBackupName);
}

bool AtomicFile::hasBackup() const {
    return existsImpl(mBackupName);
}

void AtomicFile::remove() {
    if (existsImpl(mBaseName)) {
        std::remove(mBaseName.c_str());
    }
    if (existsImpl(mBackupName)) {
        std::remove(mBackupName.c_str());
    }
}

bool AtomicFile::existsImpl(std::string name) const {
    struct stat my_stat;
    return (stat(name.c_str(), &my_stat) == 0);
}


} // namespace hht