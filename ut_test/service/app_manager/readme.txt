执行前，需要把以下文件拷贝到appManageUT2这个可执行文件同目录下
  ut_test/service/app_manager/app_config_normal.json  
  build/service/app_manager/appManagerEntry  
  build/service/app_managerlibappLib.so
然后执行appManageUT2这个可执行文件，这个文件会去执行appManagerEntry，而appManagerEntry
会拉起testProcess这个测试进程，这个testProcess进程会自动退出，退出后，程序会检查是否存在
僵尸进程
