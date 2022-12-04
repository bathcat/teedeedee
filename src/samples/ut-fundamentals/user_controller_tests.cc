#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include <string>
#include "user_controller.h"
#include "logger.h"

using namespace utFundamentals;
using namespace std;

namespace
{

    class MockLogger : public Logger
    {
    public:
        MOCK_METHOD(void, Info, (string message), (override));
        MOCK_METHOD(void, Debug, (string message), (override));
        MOCK_METHOD(void, Error, (string message), (override));
        MOCK_METHOD(void, Warn, (string message), (override));
    };

    TEST(UserControllerTests, TrueShouldBeTrue)
    {
        EXPECT_EQ(true, true);
    }

    TEST(UserControllerTests, CreateNewShouldAssignID)
    {
        MockLogger logger;
        const int id = 1000;
        UserController uc(logger,id);
        auto u = uc.CreateNew("Joe", "Bloggs");
        EXPECT_EQ(u.id, id);
    }


}