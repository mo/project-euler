#include "gtest/gtest.h"

#include "brute_force_generator.h"

TEST(BruceForceGenerator, BasicUseCaseOne) {
  BruteForceGenerator gen("abc");
  EXPECT_EQ("a", gen.nextString());
  EXPECT_EQ("b", gen.nextString());
  EXPECT_EQ("c", gen.nextString());
  EXPECT_EQ("aa", gen.nextString());
  EXPECT_EQ("ab", gen.nextString());
  EXPECT_EQ("ac", gen.nextString());
  EXPECT_EQ("ba", gen.nextString());
}

TEST(BruceForceGenerator, BasicUseCaseTwo) {
  BruteForceGenerator gen("0123456789");
  EXPECT_EQ("0", gen.nextString());
  EXPECT_EQ("1", gen.nextString());
  EXPECT_EQ("2", gen.nextString());
  EXPECT_EQ("3", gen.nextString());
  EXPECT_EQ("4", gen.nextString());
  EXPECT_EQ("5", gen.nextString());
  EXPECT_EQ("6", gen.nextString());
  EXPECT_EQ("7", gen.nextString());
  EXPECT_EQ("8", gen.nextString());
  EXPECT_EQ("9", gen.nextString());
  EXPECT_EQ("00", gen.nextString());
  EXPECT_EQ("01", gen.nextString());
  EXPECT_EQ("02", gen.nextString());
  EXPECT_EQ("03", gen.nextString());
  EXPECT_EQ("04", gen.nextString());
  EXPECT_EQ("05", gen.nextString());
  EXPECT_EQ("06", gen.nextString());
  EXPECT_EQ("07", gen.nextString());
  EXPECT_EQ("08", gen.nextString());
  EXPECT_EQ("09", gen.nextString());
  EXPECT_EQ("10", gen.nextString());
  EXPECT_EQ("11", gen.nextString());
  EXPECT_EQ("12", gen.nextString());
  EXPECT_EQ("13", gen.nextString());
  EXPECT_EQ("14", gen.nextString());
  EXPECT_EQ("15", gen.nextString());
  EXPECT_EQ("16", gen.nextString());
  EXPECT_EQ("17", gen.nextString());
  EXPECT_EQ("18", gen.nextString());
  EXPECT_EQ("19", gen.nextString());
}

TEST(BruceForceGenerator, BasicUseCaseThree) {
  BruteForceGenerator gen("ab");
  EXPECT_EQ("a", gen.nextString());
  EXPECT_EQ("b", gen.nextString());
  EXPECT_EQ("aa", gen.nextString());
  EXPECT_EQ("ab", gen.nextString());
  EXPECT_EQ("ba", gen.nextString());
  EXPECT_EQ("bb", gen.nextString());
  EXPECT_EQ("aaa", gen.nextString());
  EXPECT_EQ("aab", gen.nextString());
  EXPECT_EQ("aba", gen.nextString());
  EXPECT_EQ("abb", gen.nextString());
  EXPECT_EQ("baa", gen.nextString());
  EXPECT_EQ("bab", gen.nextString());
  EXPECT_EQ("bba", gen.nextString());
  EXPECT_EQ("bbb", gen.nextString());
  EXPECT_EQ("aaaa", gen.nextString());
}

TEST(BruceForceGenerator, CustomInitialLength2) {
  BruteForceGenerator gen("ab", 2);
  EXPECT_EQ("aa", gen.nextString());
  EXPECT_EQ("ab", gen.nextString());
  EXPECT_EQ("ba", gen.nextString());
  EXPECT_EQ("bb", gen.nextString());
  EXPECT_EQ("aaa", gen.nextString());
}

TEST(BruceForceGenerator, CustomInitialLength3) {
  BruteForceGenerator gen("ab", 3);
  EXPECT_EQ("aaa", gen.nextString());
  EXPECT_EQ("aab", gen.nextString());
  EXPECT_EQ("aba", gen.nextString());
  EXPECT_EQ("abb", gen.nextString());
  EXPECT_EQ("baa", gen.nextString());
  EXPECT_EQ("bab", gen.nextString());
  EXPECT_EQ("bba", gen.nextString());
  EXPECT_EQ("bbb", gen.nextString());
  EXPECT_EQ("aaaa", gen.nextString());
}
