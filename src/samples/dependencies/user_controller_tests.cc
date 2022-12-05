#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include <string>
#include "user_controller.h"
#include "logger.h"

using namespace dependencies;
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

    TEST(UserControllerTests, DISABLED_TrueShouldBeTrue)
    {
        EXPECT_EQ(true, false);
    }

    TEST(UserControllerTests, CreateNewShouldAssignID)
    {
        //Arrange
        MockLogger logger;
        const int id = 1000;
        UserController uc(logger,id);

        //Act
        auto u = uc.CreateNew("Joe", "Bloggs");

        //Assert
        EXPECT_EQ(u.id, id);
    }

    TEST(UserControllerTests, CreateNewShouldThrowOnEmptyGivenName)
    {
        //Arrange
        MockLogger logger;
        const int id = 1000;
        UserController uc(logger,id);

        //Act & Assert
        EXPECT_THROW(uc.CreateNew("", "Bloggs"),std::invalid_argument );
    }




}