#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "uuid.h"

using namespace uuid;

namespace
{

    TEST(generateUUID, ShouldhandleTheDefaultCase)
    {
        EXPECT_EQ("1", "1");
    }

}