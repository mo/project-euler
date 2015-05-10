#include "gtest/gtest.h"

#include "utils.h"

using namespace std;

TEST(split, Basic) {
  EXPECT_EQ((vector<string>{"a", "b"}), split("a b"));
  EXPECT_EQ((vector<string>{"a", "b"}), split(" a b "));
  EXPECT_EQ((vector<string>{"a", "b"}), split("  a  b  "));
}

TEST(split, CornerCases) {
  EXPECT_EQ(0, split("").size());
  EXPECT_EQ(0, split(" ").size());
  EXPECT_EQ(0, split("  ").size());
}

TEST(join, Basic) {
  EXPECT_EQ("a b", join((vector<string>{"a", "b"}), " "));
  EXPECT_EQ("a", join((vector<string>{"a"}), " "));
}

TEST(join, CornerCases) {
  EXPECT_EQ("", join((vector<string>{}), " "));
  EXPECT_EQ(" ", join((vector<string>{" "}), " "));
  EXPECT_EQ("a  ", join((vector<string>{"a", " "}), " "));
  EXPECT_EQ("   ", join((vector<string>{" ", " "}), " "));
  EXPECT_EQ(" a ", join((vector<string>{" ", " "}), "a"));
}

TEST(trim, Basic) {
  EXPECT_EQ("abc", trim(" abc "));
  EXPECT_EQ("abc", trim(" abc    "));
  EXPECT_EQ("a bc", trim(" a bc    "));
}

TEST(trim, CornerCases) {
  EXPECT_EQ("", trim(""));
  EXPECT_EQ("", trim(" "));
  EXPECT_EQ("", trim("  "));
  EXPECT_EQ("", trim(" \n\n \t\t "));
}

TEST(drop_duplicates, Basic) {
  auto expected = (vector<string>{"a", "b"});
  vector<string> input = (vector<string>{"a", "a", "b"});
  auto actual = drop_duplicates(input);
  EXPECT_EQ(expected, actual);
}
