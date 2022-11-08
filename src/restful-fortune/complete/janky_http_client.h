#ifndef HTTPCLIENT_H_
#define HTTPCLIENT_H_

#include <string>
#include "httplib.h"
#include "http_client.h"

namespace fortune
{

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


}

#endif
