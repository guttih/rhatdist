//  File testCodeExample.cpp, created 2022-06-28 22:29:44.
//
#include <stdlib.h>
#include "testCodeExample.h"
#include "String.h"
#include "Json.h"

int test_func()
{
    return 1;
}

int test_func2()
{
    return 2;
}
std::string test_Json()
{
    String str="{\"hello\":\"world\"}";
    Json j(str.c_str());
    printf("inString: %s", str.c_str());
    printf("J:tostring: %s", j.toString().c_str());
   
    return 
    j.toString().c_str();
}
