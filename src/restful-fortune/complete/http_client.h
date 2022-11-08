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

}

#endif
