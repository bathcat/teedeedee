#ifndef HTTPCLIENTADAPTER_H_
#define HTTPCLIENTADAPTER_H_

#include <string>
#include <tuple>
#include "http_client.h"
#include "httplib.h"
#include "uri.h"

namespace fortune
{

    class HttpClientAdapter : public fortune::HttpClient
    {

    public:
        virtual HttpResponse Get(std::string uri) override
        {
            // TODO: Because httplib is janky, and separates construction (with the protocol + domain)
            //       from GET (with the trunk, we need to separate them out.)
            auto segments = fortune::uri::parse(uri);

            httplib::Client httpClient(std::get<0>(segments));
            const auto result = httpClient.Get(std::get<1>(segments));
            const auto response = result.value();
            return HttpResponse(response.status, response.body);
        }
    };

}

#endif
