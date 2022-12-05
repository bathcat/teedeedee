#ifndef HTTP_REQUEST_H_
#define HTTP_REQUEST_H_

#include <string>

using namespace std;

namespace stupid_gmock_tricks
{
  struct HttpRequest
  {
    string resource;
    string token;
    string body;
    string method;
    HttpRequest(string _resource, string _token, string _method, string _body)
        : token(_token),
          body(_body),
          resource(_resource),
          method(_method)
    {
    }
  };

}

#endif