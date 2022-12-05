#ifndef HTTP_RESPONSE_H_
#define HTTP_RESPONSE_H_

#include <string>

using namespace std;

namespace stupid_gmock_tricks
{
  struct HttpResponse
  {
    int status;
    string body;
    HttpResponse(int _status, string _body)
        : status(_status),
          body(_body)
    {
    }
  };

}

#endif