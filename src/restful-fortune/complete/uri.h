#ifndef URI_H_
#define URI_H_

#include <tuple>
#include <string>

namespace fortune
{


    namespace uri{

        std::tuple<std::string,std::string> parse(std::string uri){
            auto pos = uri.find("/",9);
            std::string root = uri.substr(0,pos);
            std::string leaf = uri.substr(pos,uri.length());

            return std::make_tuple(root,leaf);
        }

    }

}

#endif
