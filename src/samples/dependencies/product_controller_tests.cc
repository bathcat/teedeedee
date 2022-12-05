#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include <string>
#include "product_controller.h"
#include "c_logger.h"


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



    TEST(ProductControllerTests, TrueShouldBeTrue)
    {
        EXPECT_EQ(true, true);
    }


    TEST(ProductControllerTests, CreateNewShouldAssignID)
    {
        //Arrange
        MockLogger logger;
        const int id = 1000;
        ProductController<MockLogger> pc(logger,id);

        //Act
        auto p = pc.CreateNew("Joe", "Bloggs");

        //Assert
        EXPECT_EQ(p.id, id);
    }

    TEST(ProductControllerTests, CreateNewShouldThrowOnEmptyName)
    {
        //Arrange
        MockLogger logger;
        const int id = 1000;
        ProductController pc(logger,id);

        //Act & Assert
        EXPECT_THROW(pc.CreateNew("", "Lorem ipsum..."),std::invalid_argument );
    }

    TEST(ProductControllerTests, CreateNewShouldLogInfo)
    {
        //Arrange
        MockLogger logger;
        EXPECT_CALL(logger, Info(A<string>()))      
            .Times(1);

        const int id = 1000;
        ProductController pc(logger,id);

        //Act 
        auto newP = pc.CreateNew("Enfarculator P1000", "Lorem ipsum...");
        
        
        // Assert (Implicit)
    }


}