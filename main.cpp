#include <string>
#include <chrono>
#include <tuple>
#include <iostream>
#include "sw/redis++/redis++.h"

using namespace sw::redis;
#pragma comment(lib, "Ws2_32.lib")
int main(){
    try {
       
       std::cout << "hello" <<std::endl;
    
      Redis redis("tcp://172.31.94.226");
      std::cout << "COnnecting\n";
      redis.set("ahmed", "123");
      auto val = redis.get("ahmed");    // val is of type OptionalString. See 'API Reference' section for details.
      if (val) {
        //Dereference val to get the returned value of std::string type.
        std::cout << *val << std::endl;
       }   // else key doesn't exist.
    }       
    catch (const Error& err) {
        // other errors
        std::cout << err.what() << std::endl;

    }
}