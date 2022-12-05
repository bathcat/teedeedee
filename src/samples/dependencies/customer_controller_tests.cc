#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include <string>
#include "customer_controller.h"

using namespace dependencies;
using namespace std;
using namespace testing;

namespace
{

    class MockLogger 
    {
    public:
        MOCK_METHOD(void, Info, (string message), ());
        MOCK_METHOD(void, Debug, (string message), ());
        MOCK_METHOD(void, Error, (string message), ());
        MOCK_METHOD(void, Warn, (string message), ());
    };


    TEST(CustomerControllerTests, CreateNewShouldAssignID)
    {
        //Arrange
        MockLogger logger;
        const int id = 1000;
        CustomerController<MockLogger> cc(logger,id);

        //Act
        auto p = cc.CreateNew("Joe", "Bloggs");

        //Assert
        EXPECT_EQ(p.id, id);
    }

    TEST(CustomerControllerTests, CreateNewShouldThrowOnEmptyName)
    {
        //Arrange
        MockLogger logger;
        const int id = 1000;
        CustomerController cc(logger,id);

        //Act & Assert
        EXPECT_THROW(cc.CreateNew("", ""),std::invalid_argument );
    }

    TEST(CustomerControllerTests, CreateNewShouldLogInfo)
    {
        //Arrange
        MockLogger logger;
        EXPECT_CALL(logger, Info(A<string>()))      
            .Times(1);

        const int id = 1000;
        CustomerController cc(logger,id);

        //Act 
        auto newC = cc.CreateNew("Enfarculator P1000", "Lorem ipsum...");
        
        
        // Assert (Implicit)
    }


}