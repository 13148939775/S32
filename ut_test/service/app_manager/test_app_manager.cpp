#include <gtest/gtest.h>

#include <service/app_manager/app_manager.h>

namespace HHT {
class TestAppM : public HDBMApp {
public:
    TestAppM(std::string name, bool isService = false)
      : HDBMApp(name, "", isService)
    { }

    ~TestAppM()
    { }
};

TEST(AppManager, Init)
{
  TestAppM appA("testA");
  appA.DoInit();
  EXPECT_TRUE(appA.GetStatus() == AppStatus::Initialized);
}

TEST(AppManager, Stop)
{
  TestAppM appA("testA");
  appA.DoStop();
  EXPECT_TRUE(appA.GetStatus() == AppStatus::Normal_Stopped);
}
}