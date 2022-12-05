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
    string method;
    string body;
    HttpRequest(string _resource, string _token, string _method, string _body)
        : 
          resource(_resource),
          token(_token),
          method(_method),
          body(_body)
    {
    }
  };

}

#endif