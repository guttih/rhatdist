//  File main.cpp, created 2022-06-28 22:29:44.
//
#include "CppUTest/TestHarness.h"
#include "testCodeExample.h"

TEST_GROUP(AwesomeExamples)
{
};

TEST(AwesomeExamples, FirstExample)
{
  int x = test_func();
  CHECK_EQUAL(1, x);
}

TEST(AwesomeExamples, second)
{
  std::string str= test_Json();
  STRCMP_EQUAL("{\"hello\":\"world\"}", str.c_str());
}
