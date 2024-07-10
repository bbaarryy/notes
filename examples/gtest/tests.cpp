#include <gtest/gtest.h>
#include "code.cpp"

using namespace std;

TEST(TestGroup, Test_1)
{
  vector<ll> a = {4,1,2,3};
  vector<ll> b = {7,2,5,6};
  auto result = solve(4, 2, 3, 2, a,b);
  EXPECT_EQ("Bodya", result);
}

TEST(TestGroup, Test_2)
{
  vector<ll> a = {3, 1, 4, 5, 2 ,7 ,8 ,10, 6, 9};
  vector<ll> b = {5, 10, 5 ,1 ,3 ,7 ,10, 15, 4, 3};
  auto result = solve(10, 8, 2, 10, a,b);
  EXPECT_EQ("Sasha", result);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
