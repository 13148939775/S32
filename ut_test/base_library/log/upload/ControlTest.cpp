#include <gtest/gtest.h>
#include <sstream>
#include "Control.h"

TEST(ControlTest, ScheduleUploadTest) {
    Control control;

    // 调用被测试函数
    bool res = control.ScheduleUpload();
    EXPECT_TRUE(res);
}