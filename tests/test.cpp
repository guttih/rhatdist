//  File main.cpp, created 2022-06-12 23:11:37.
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
