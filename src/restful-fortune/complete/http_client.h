#ifndef HTTPCLIENT_H_
#define HTTPCLIENT_H_

#include <string>
#include "httplib.h"

namespace fortune
{

    struct HttpResponse
    {
        unsigned short status;
        std::string body;
    
        HttpResponse(unsigned short status, std::string body)
        {
            status=status;
            body=body;
        }
    };

    class HttpClient
    {
    public:
        virtual ~HttpClient() {}
        virtual HttpResponse Get(std::string uri) = 0;
    };

    namespace internal{
        class AdapterHttpClient : public HttpClient{

            public:
            virtual HttpResponse Get(std::string uri) override{
                //TODO: Because httplib is janky, and separates construction from get, 
                //      this probably won't work with 1 url string if there's e.g. query strings since you can't append those to the end.
                httplib::Client client(uri);
                const auto response = client.Get("/").value();
                return HttpResponse(response.status,response.body);
            }
        };
    }

    HttpClient getClient(){
        return internal::AdapterHttpClient();
    }

}

#endif

int main(const int argc, const char **argv)
{

    if (argc > 1)
    {
        std::cout << usage << std::endl;
        return 0;
    }

    httplib::Client cli("http://api.kanye.rest");
    const auto res = cli.Get("/");
    const auto jsn = nlohmann::json::parse(res.value().body);

    std::cout << "Body:" << jsn["quote"] << std::endl;

    return 0;
}
