#include "primes.h"

#include <vector>
#include <cmath>

using namespace std;

uint64_t sum_of_primes_below(uint64_t limit) {
  vector<bool> is_prime(limit, true);
  // Note: sqrt() takes a double which cannot represent all uint64_t values, but
  // for the purposes of summing up primes this ends up being correct anyway.
  for (uint64_t n = 2; n <= (uint64_t)sqrt(limit); ++n) {
    if (is_prime[n]) {
      for (uint64_t composite = n * n; composite < limit; composite += n) {
        is_prime[composite] = false;
      }
    }
  }
  uint64_t sum = 0;
  for (uint64_t i = 2; i < limit; ++i) {
    if (is_prime[i]) {
      sum += i;
    }
  }
  return sum;
}
