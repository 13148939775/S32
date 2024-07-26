/*
 * @author 008555
 * @for application log interface
 * @version 0.1
 * @date 2023-11 ~ 2023-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <thread>
#include <gtest/gtest.h>

void RunUTest(int argc,char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    RUN_ALL_TESTS();
}


int main(int argc,char **argv) {

    std::thread th_(std::bind(&RunUTest, argc, argv));
    th_.join();
    
    return 0;
}

