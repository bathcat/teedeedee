#include <gtest/gtest.h>
#include "gmock/gmock.h"

#include <tuple>
#include "uri.h"

namespace
{

    TEST(Parse, ShouldHandleHttp)
    {
        const auto result = fortune::uri::parse("http://example.com/something/something");
        EXPECT_EQ(std::get<0>(result), "http://example.com");
        EXPECT_EQ(std::get<1>(result), "/something/something");
    }

    TEST(Parse, ShouldHandleHttps)
    {
        const auto result = fortune::uri::parse("https://example.com/something/something");
        EXPECT_EQ(std::get<0>(result), "https://example.com");
        EXPECT_EQ(std::get<1>(result), "/something/something");
    }

}