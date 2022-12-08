#include <gtest/gtest.h>
#include "gmock/gmock.h"

#include "fortune_generator.h"
#include "http_client.h"

using namespace fortune;
using namespace testing;

namespace
{

    class FakeHttpClient : public HttpClient
    {
    public:
        HttpResponse Get(std::string url) override{
            
          return HttpResponse(200,
             "{\"text\": \"xyz\"}"
          );
        }
    };

    TEST(FortuneGeneratorTests, TrueShouldBeTrue)
    {
        FakeHttpClient client;
        FortuneGenerator generator(client);
        auto actual = generator.getFortune();

        EXPECT_EQ(actual,"xyz");

        
    }

}