#include "gtest/gtest.h"

#include "primes.h"

TEST(sum_of_primes_below, Basic) {
  EXPECT_EQ(17, sum_of_primes_below(10));
  EXPECT_EQ(142913828922, sum_of_primes_below(2000000));
}
