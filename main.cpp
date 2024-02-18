#include <string>
#include <chrono>
#include <tuple>
#include <iostream>
#include "sw/redis++/redis++.h"

using namespace sw::redis;
#pragma comment(lib, "Ws2_32.lib")
int main(){
    try {    
      Redis redis("tcp://172.31.94.226");
      std::cout << redis.ping() << std::endl;

    }       
    catch (const Error& err) {
        // other errors
        std::cout << err.what() << std::endl;
    }
}