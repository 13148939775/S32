#include <gtest/gtest.h>
#include <iostream>
#include <cstring>
#include <string>
#include <unistd.h>
#include <algorithm>


int MyTest()
{

    FILE* pipe = popen("ps aux | grep 'Z' | grep -v grep | wc -l", "r");
    if (!pipe) {
        return 0;
    }

    char buffer[128];
    std::string result = "";

    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != nullptr) {
            result += buffer;
        }
    }

    pclose(pipe);

    // Remove trailing newline characters from the result
     result.erase(std::remove_if(result.begin(), result.end(), [](char c) { return c == '\n'; }), result.end());

    int zombieCnt = std::stoi(result);

    return zombieCnt;//使用ps aux | grep 'Z' 命令时，默认会输出一行眉头，所以wc时至少是1
}


TEST(HDBMApp,zombie)
{
	pid_t pid=fork();
	if (pid == -1) {
	   return;
	}
	else if (pid>0) {
           sleep(6);

           int res = MyTest();
           EXPECT_TRUE(res==1);

	   sleep(3);
           const char* command = "killall appManagerEntry";
           int result = std::system(command);
	   //in case of memnory leak kill appManager process
	}
	else if (pid==0) {
     	     const char* programPath = "./appManagerEntry";  // 可执行文件的路径
             char* const arguments[] = {const_cast<char*>(programPath), const_cast<char*>("0"), nullptr};  // 参数列表

             if (execv(programPath, arguments) == -1) {
               // execv 函数执行失败
               exit(1);
           }
       }
}
