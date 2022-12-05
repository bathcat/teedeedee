#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include <string>
#include "service_gateway.h"
#include "logger.h"
#include "user_controller.h"

using namespace stupid_gmock_tricks;
using namespace std;
using namespace testing;

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

    TEST(ServiceGatewayTests, TrueShouldBeTrue)
    {
        // Arrange
        MockLogger logger;
        auto userController = UserController(logger);

        // ServiceGateway gateway;

        // Act

        // Assert
        EXPECT_EQ(true, true);
    }

}