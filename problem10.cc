#include <vector>
#include <stdint.h>
#include <math.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>

using namespace std;

uint64_t sum_of_primes_below(uint64_t limit) {
    std::vector<bool> is_prime(limit, true);
    for (uint64_t n = 2; n <= (int) sqrt(limit); ++n) {
        if (is_prime[n]) {
            for (uint64_t composite = n*n; composite < limit; composite += n) {
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

bool is_prime(uint64_t num) {
    if (num % 2 == 0) {
        return num == 2;
    }
    if (num % 3 == 0) {
        return num == 3;
    }
    for (uint64_t k = 6; k - 1 < num; k += 6) {
        if (num % (k - 1) == 0) {
            return num == k - 1;
        }
        if (num % (k + 1) == 0) {
            return num == k + 1;
        }
    }
    return true;
}

int main() {
    assert(sum_of_primes_below(10) == 17);
    printf("answer = %lu\n", sum_of_primes_below(2000000));
    return 0;
}
