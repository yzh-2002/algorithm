#include <string>
#include <iostream>
#include "hash_map.h"

int main(){
    HashMap<int,std::string> map(10);
    map.put(1,"yangzihan");
    std::cout << map.get(1) << std::endl;
    return 0;
}