#ifndef HTTPCLIENT_H_
#define HTTPCLIENT_H_

#include <string>


namespace fortune
{

    struct HttpResponse
    {
        unsigned short status;
        std::string body;
    
        HttpResponse(unsigned short status_, std::string body_)
        {
            status=status_;
            body=body_;
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
