#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "base64.h"
#include "TspProxy.h"

// 定义一个Mock类来模拟BaseMac类
class MockBaseMac : public BaseMac {
public:
    MOCK_METHOD(std::string, base64_encode, (const unsigned char*, unsigned int));
};

// 定义测试用例
TEST(BaseMacTest, base64_encode) {
    MockBaseMac baseMac;
    unsigned char encode[] = {'H', 'e', 'l', 'l', 'o'};
    unsigned int len = sizeof(encode);
    std::string expectedResult = "SGVsbG8=";

    // 为base64_encode方法设置预期行为
    EXPECT_CALL(baseMac, base64_encode(encode, len))
        .WillOnce(testing::Return(expectedResult));

    std::string encodedStr = baseMac.base64_encode(encode, len);
    EXPECT_EQ(encodedStr, expectedResult);
}