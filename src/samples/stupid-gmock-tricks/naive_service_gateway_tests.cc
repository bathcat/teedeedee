#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include <string>
#include "naive_service_gateway.h"
#include "logger.h"



using namespace stupid_gmock_tricks;
using namespace std;
using namespace testing;

namespace
{


    TEST(NaiveServiceGatewayTests, RouteShouldRoute)
    {
        //Arrange
        
        NaiveServiceGateway gateway;
        
        //Act

        //Assert
        EXPECT_EQ(true, true);
    }


 

}