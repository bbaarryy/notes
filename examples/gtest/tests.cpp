#include <gtest/gtest.h>
#include "code.cpp"

using namespace std;

TEST(TestGroup, Test_1) 
{
  auto result = solve_function(1,1);

  EXPECT_EQ(2,result);
}

TEST(TestGroup, Test_2) 
{
  auto result = solve_function(5,1);

  EXPECT_NE(2,result);
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
