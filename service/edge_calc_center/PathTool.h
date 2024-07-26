#ifndef PATHTOOL_H
#define PATHTOOL_H

#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#include <set>

#include "HhtStrTool.h"

namespace HHT {
namespace DataManager {
class PathTool {
public:
    static inline bool isAbs(const std::string& path) {
        return path.size() ? '/' == path.at(0): false;
    }

    static inline bool isRel(const std::string& path) {
        return !isAbs(path);
    }

    static std::string normPath(const std::string& path) {
        std::list<std::string> ptli = StrTool::split(path, "/");
        size_t skipCount = 0;

        //rit = list<int>::reverse_iterator(l.erase((++rit).base())
        for (auto rit = ptli.rbegin(); rit != ptli.rend(); ) {
            if (0 == rit->size() || (*rit) == ".") {
                rit = std::list<std::string>::reverse_iterator(ptli.erase((++rit).base()));
            } else if ((*rit) == "..") {
                ++skipCount;
                rit = std::list<std::string>::reverse_iterator(ptli.erase((++rit).base()));
            } else if (skipCount) {
                --skipCount;
                rit = std::list<std::string>::reverse_iterator(ptli.erase((++rit).base()));
            } else {
                ++rit;
            }
        }
        if (isAbs(path)) {
            ptli.push_front("");
        } else {
            while (skipCount) {
                --skipCount;
                ptli.push_front("..");
            }
        }

        return ptli.size() ? StrTool::join(ptli, "/") : std::string(".");
    }

    static std::string absPath(const std::string& path) {
        if (isAbs(path)) {
            return normPath(path);
        }

        static constexpr size_t PATH_MAX_LEN = 512;

        char root[PATH_MAX_LEN] = {'\0'};
        getcwd(root, PATH_MAX_LEN);
        return join(root, path);
    }

    static std::string join(const std::string& root, const std::string& path) {
        if (isAbs(path)) {
            return normPath(path);
        }
        return normPath(root + "/" + path);
    }

    static bool isExist( const std::string& path) {
        return access(path.c_str(), 0) != -1;
    }

    static bool isDir( const std::string& path) {
        struct stat buf;
        int ret = stat(path.c_str(), &buf);
        return (ret != -1) && S_ISDIR(buf.st_mode);

        return access(path.c_str(), 0) != -1;
    }

    static bool rmPath(const std::string& path, bool recursived = true) {
        int ret = 0;
        if (!isDir(path)) {
            ret = remove(path.c_str());
            return ret != -1;
        }

        if (!recursived) {
            ret = rmdir(path.c_str());
            return ret != -1;
        }

        DIR* dir = opendir(path.c_str());
        if (nullptr == dir) {
            return false;
        }

        struct dirent* dirp;
        while ((dirp = readdir(dir))) {
            if ((strcmp(dirp->d_name, ".") == 0) || (strcmp(dirp->d_name, "..") == 0)) {
                continue;
            }

            std::string filepath = join(path, dirp->d_name);
            if (!isDir(filepath)) {
                // remove child file
                remove(filepath.c_str());
            } else {
                // remvoe subdir
                rmPath(filepath, true);
            }
        }
        closedir(dir);
        ret = rmdir(path.c_str());

        return ret != -1;
    }

    static size_t fileLength(const std::string& path) {
        int fd = open(path.c_str(), O_RDONLY);
        if (-1 == fd) {
            return 0;
        }

        struct stat buf;
        int ret = fstat(fd, &buf);
        if (ret == -1) {
            close(fd);
            return 0;
        }
        close(fd);
        return buf.st_size;
    }

    static void walkDir(const std::string& path, std::list<std::string>& dirs_o,
                        std::list<std::string>& files_o) {
        if (!isDir(path)) {
            return;
        }

        DIR* dir = opendir(path.c_str());
        if (nullptr == dir) {
            return;
        }

        struct dirent* dirp;
        while ((dirp = readdir(dir))) {
            if ((strcmp(dirp->d_name, ".") == 0) || (strcmp(dirp->d_name, "..") == 0)) {
                continue;
            }

            std::string childPath = join(path, dirp->d_name);
            if (isDir(childPath)) {
                // TODO:
                dirs_o.push_back(dirp->d_name);
                std::list<std::string> subDirs;
                std::list<std::string> subFiles;
                walkDir(childPath, subDirs, subFiles);
                for (auto& subdirPath: subDirs) {
                    dirs_o.push_back(join(dirp->d_name, subdirPath));
                }

                for (auto& subfilePath: subFiles) {
                    files_o.push_back(join(dirp->d_name, subfilePath));
                }
            } else {
                files_o.push_back(dirp->d_name);
            }
        }
        closedir(dir);
    }

    static size_t deep(const std::string& path) { return StrTool::split(normPath(path), "/").size(); }

    static std::pair<std::string, std::string> split(const std::string& path) {
        size_t idx = path.find_last_of("/");
        if (std::string::npos == idx) {
            return {std::string(), path};
        }
        return {path.substr(0, idx), path.substr(idx + 1)};
    }

    static std::string dirName(const std::string& path) {
        return split(path).first;
    }

    static std::string baseName(const std::string& path) {
        return split(path).second;
    }

    static bool mkDir(const std::string& dirPath, bool mkParents = false) {
        if (!mkParents) {
            int ret = mkdir(dirPath.c_str(), S_IRWXU | S_IRWXG | S_IROTH);
            return ret != -1;
        }

        // mkParents == true
        std::string fullPath = absPath(dirPath);
        std::list<std::string> fullPathLi = StrTool::split(fullPath, "/");
        fullPathLi.erase(fullPathLi.begin());
        if (fullPathLi.empty()) {
            // is root path
            return false;
        }

        std::string locPath("/");
        for (auto& piece: fullPathLi) {
            locPath = join(locPath, piece);
            if (!isExist(locPath)) {
                int ret = mkdir(locPath.c_str(), S_IRWXU | S_IRWXG | S_IROTH);
                if (ret == -1) {
                    return false;
                }
            } else if (!isDir(locPath)) {
                // exist, but not dir
                return false;
            } else {
                // continue
            }
        }
        return true;
    }

public:
    static std::string lstrip(const std::string& path) {
        static std::set<char> BLANK_CHS = {' ', '\t', '\v', '\r', '\n', '\f'};
        size_t idx = 0;
        for (; idx < path.size(); ++idx) {
            if (0 == BLANK_CHS.count(path.at(idx))) {
                break;
            }
        }
        return idx? path.substr(idx): path;
    }

    static std::string rstrip(const std::string& path) {
        static std::set<char> BLANK_CHS = {' ', '\t', '\v', '\r', '\n', '\f'};
        size_t ridx = 0;
        for (; ridx < path.size(); ++ridx) {
            if (0 == BLANK_CHS.count(path.at(path.size() - ridx - 1))) {
                break;
            }
        }
        return ridx? path.substr(0, path.size() - ridx): path;
    }

    static inline std::string strip(const std::string& path) {
        return rstrip(lstrip(path));
    }
};

}  // namespace datamanager
}  // namespace hht
#endif	// PATHTOOL_H
