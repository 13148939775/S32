/*
 * @author 008196
 * @for application log interface
 * @version 0.1
 * @date 2023-02 ~ 2023-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>

#include <service/app_manager/hdbm_app.h>

namespace HHT {
class TestApp : public HDBMApp, public testing::Test {
public:
    TestApp()
      : HDBMApp("test")
    { }

    ~TestApp()
    { }

    bool Stop()
    {
        return true;
    }
protected:
    virtual void SetUp()
    { }
    virtual void TearDown()
    { }
    virtual void TestBody()
    { }
};

TEST(HDBMApp, Start)
{
  TestApp app;
  app.DoInit();
  EXPECT_TRUE(app.GetStatus() == AppStatus::Initialized);
}

TEST(HDBMApp, Stop)
{
  TestApp app;
  app.DoStart();
  EXPECT_TRUE(app.GetStatus() == AppStatus::Started);
}
}