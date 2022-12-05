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

    class ServiceGatewayTest : public ::testing::Test
    {
    protected:
        MockLogger _logger;
        UserController _userController;
        ProductController _productController;
        AuthenticationController _authenticationController;
        CustomerController _customerController;
        ServiceGateway gateway;

        ServiceGatewayTest()
            : _userController(_logger),
              _productController(_logger),
              _authenticationController(_logger),
              _customerController(_logger),
              gateway(_logger, _userController, _productController, _customerController, _authenticationController)

        {
        }
    };

    TEST_F(ServiceGatewayTest, GetControllerShouldParseCustomersRequest)
    {
        // Act
        auto controller = gateway.getController(HttpRequest("/customers/create", "0x1281a", "POST", "{}"));

        // Assert
        EXPECT_EQ(controller, "CustomerController");
    }

    TEST_F(ServiceGatewayTest, GetControllerShouldParseProductsRequest)
    {
        // Act
        auto controller = gateway.getController(HttpRequest("/products/11", "0x1281a", "GET", ""));

        // Assert
        EXPECT_EQ(controller, "ProductController");
    }

    TEST_F(ServiceGatewayTest, GetControllerShouldParseUsersRequest)
    {
        // Act
        auto controller = gateway.getController(HttpRequest("/users/11", "0x1281a", "GET", ""));

        // Assert
        EXPECT_EQ(controller, "UserController");
    }

    TEST_F(ServiceGatewayTest, GetControllerShouldDefaultToErrorController)
    {
        // Act
        auto controller = gateway.getController(HttpRequest("/uuusers/11", "0x1281a", "GET", ""));

        // Assert
        EXPECT_EQ(controller, "ErrorController");
    }

}
