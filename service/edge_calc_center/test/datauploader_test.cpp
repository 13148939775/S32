#include "ApaDataBridge.h"

#include <unistd.h>

#include <glog/logging.h>

int main(int argc, char** argv) {
    hht::ApaDataBridge adb;
    adb.init();
    LOG(ERROR) << "init ApaDataBridge.";

    while(1) {
        sleep(1);
    }
    return 0;
}