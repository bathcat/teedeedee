#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include <string>
#include "service_gateway.h"
#include "logger.h"
#include "user_controller.h"
#include "product_controller.h"
#include "authentication_controller.h"
#include "customer_controller.h"

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

    TEST(ServiceGatewayTests, GetControllerShouldParseCustomersRequest)
    {
        // Arrange
        MockLogger logger;
        auto userController = UserController(logger);
        auto productController = ProductController(logger);
        auto authenticationController = AuthenticationController(logger);
        auto customerController = CustomerController(logger);

        ServiceGateway gateway(logger, userController, productController, customerController, authenticationController);

        // Act
        auto controller = gateway.getController(HttpRequest("/customers/create", "0x1281a", "POST", "{}"));

        // Assert
        EXPECT_EQ(controller, "CustomerController");
    }

    TEST(ServiceGatewayTests, GetControllerShouldParseProductsRequest)
    {
        // Arrange
        MockLogger logger;
        auto userController = UserController(logger);
        auto productController = ProductController(logger);
        auto authenticationController = AuthenticationController(logger);
        auto customerController = CustomerController(logger);

        ServiceGateway gateway(logger, userController, productController, customerController, authenticationController);

        // Act
        auto controller = gateway.getController(HttpRequest("/products/11", "0x1281a", "GET", ""));

        // Assert
        EXPECT_EQ(controller, "ProductController");
    }

    TEST(ServiceGatewayTests, GetControllerShouldParseUsersRequest)
    {
        // Arrange
        MockLogger logger;
        auto userController = UserController(logger);
        auto productController = ProductController(logger);
        auto authenticationController = AuthenticationController(logger);
        auto customerController = CustomerController(logger);

        ServiceGateway gateway(logger, userController, productController, customerController, authenticationController);

        // Act
        auto controller = gateway.getController(HttpRequest("/users/11", "0x1281a", "GET", ""));

        // Assert
        EXPECT_EQ(controller, "UserController");
    }

    TEST(ServiceGatewayTests, GetControllerShouldDefaultToErrorController)
    {
        // Arrange
        MockLogger logger;
        auto userController = UserController(logger);
        auto productController = ProductController(logger);
        auto authenticationController = AuthenticationController(logger);
        auto customerController = CustomerController(logger);

        ServiceGateway gateway(logger, userController, productController, customerController, authenticationController);

        // Act
        auto controller = gateway.getController(HttpRequest("/uuusers/11", "0x1281a", "GET", ""));

        // Assert
        EXPECT_EQ(controller, "ErrorController");
    }

}