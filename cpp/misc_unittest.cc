#include "gtest/gtest.h"

#include "misc.h"

TEST(has_no_duplicate_chars, BasicUseCases) {
  EXPECT_EQ(true, has_no_duplicate_chars("a"));
  EXPECT_EQ(true, has_no_duplicate_chars("ab"));
  EXPECT_EQ(false, has_no_duplicate_chars("aa"));
  EXPECT_EQ(false, has_no_duplicate_chars("aabc"));
  EXPECT_EQ(false, has_no_duplicate_chars("abbc"));
  EXPECT_EQ(false, has_no_duplicate_chars("abcc"));
  EXPECT_EQ(false, has_no_duplicate_chars("abca"));
}

TEST(has_no_duplicate_chars, CornerCases) {
  EXPECT_EQ(true, has_no_duplicate_chars(""));
  EXPECT_EQ(true, has_no_duplicate_chars(" "));
  EXPECT_EQ(false, has_no_duplicate_chars("  "));
  EXPECT_EQ(false, has_no_duplicate_chars(" a "));
  EXPECT_EQ(false, has_no_duplicate_chars("  a"));
}
