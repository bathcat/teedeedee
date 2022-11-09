#ifndef HTTPCLIENTADAPTER_H_
#define HTTPCLIENTADAPTER_H_

#include <string>
#include "http_client.h"
//#include "httplib.h"

namespace fortune
{

    class HttpClientAdapter : public fortune::HttpClient
    {

    public:
        virtual HttpResponse Get(std::string uri) override
        {
            // TODO: Because httplib is janky, and separates construction from get,
            //       this probably won't work with 1 url string if there's e.g. query strings since you can't append those to the end.
            // httplib::Client client(uri);
            // const auto response = client.Get("/").value();
            // return HttpResponse(response.status, response.body);
            return HttpResponse(400, "response.body");
        }
    };

}

#endif
