#include <cstdint>
#include <cassert>
#include <cstdio>
#include <cstdint>
#include <string>

#include "primes.h"

using namespace std;

int main(int argc, char* argv[]) {
  if (argc == 2) {
    uint64_t limit = stoul(argv[1]);
    printf("%lu\n", sum_of_primes_below(limit));
    return 0;
  }
  assert(sum_of_primes_below(10) == 17);
  printf("answer = %lu\n", sum_of_primes_below(2000000));
  return 0;
}
