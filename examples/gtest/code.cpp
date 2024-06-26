#include <iostream>
using namespace std;

int solve_function(int a, int b)
{
  return a + b;
}

#ifndef GOOGLETEST_INCLUDE_GTEST_GTEST_H_

int main(int argc, char **argv)
{
  return solve_function(3, 5);
}

#endif
