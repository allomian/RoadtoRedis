#include <string>
#include <chrono>
#include <tuple>
#include <iostream>
#include <unordered_map>
#include <iterator>
#include "sw/redis++/redis++.h"

using namespace sw::redis;
#pragma comment(lib, "Ws2_32.lib")
int main(){
    try {    
      Redis redis("tcp://172.31.94.226");
      std::cout << redis.ping() << std::endl;

      redis.set("C++","redis");
      std::cout << redis.get("C++").value() << std::endl;

      redis.setex("redis",10,"c++");
      redis.setnx("redis++","c++");

     //Lists in Redis
     
     redis.lpush("FoodItem","Pizza");
     std::cout << redis.llen("FoodItem") << std::endl;
     std::cout << redis.lpop("FoodItem").value() << std::endl;

    //Hash in Redis
    redis.hset("user:2","Name","John");
    redis.hset("user:2","Age","26");
    redis.hset("user:2","Email","John@xyz.com");


    std::cout << redis.hget("user:2","Name").value() << std::endl;


    std::unordered_map<std::string,std::string> hashData;
    redis.hgetall("user:2",std::inserter(hashData,hashData.begin()));

    for(auto &data:hashData){
        std::cout<< data.first << "==>" << data.second << std::endl;
    }

    std::string sortedSetKey = "YoutubeVideo"; 
    redis.zadd(sortedSetKey,{std::make_pair("Video1",1000),std::make_pair("video2",2000)});

    std::vector<std::pair<std::string,double>> redisSortedSetData;
    redis.zrange(sortedSetKey,0,-1,std::back_inserter(redisSortedSetData));

    for(auto [member,value]:redisSortedSetData){
        std::cout << "Member:" << member << " Value:" << value <<std::endl;
        std::cout << "Member:" << member << " Value:" << value << " Rank" <<  redis.zrank(sortedSetKey,member).value() <<std::endl;
        std::cout << "Member:" << member << " Value:" << value << " Rank" <<  redis.zrevrank(sortedSetKey,member).value() <<std::endl;
    }
    }
    catch (const Error& err) {
        // other errors
        std::cout << err.what() << std::endl;
    }
}