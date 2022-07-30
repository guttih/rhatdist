 #include <Json/Json.h>
#include <iostream>

int main()
{
    std::cout << "Hello world from configurationx\n";
     std::cout << "Json version: " << JSON_VERSION << std::endl;
     Json jd("{\"hello\":\"world\"}");
     std::cout<<jd.toString().c_str();
}