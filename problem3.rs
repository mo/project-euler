use std::num;
use std::vec;

#[test]
fn correct_answer() {
    let factors = prime_factors(600851475143);
    let expected_answer = 6857;
    let computed_answer = *factors.last();
    assert_eq!(computed_answer, expected_answer);
}

fn prime_factors(mut n: int) -> ~[int] {
    let mut divisor = 2;
    let mut factors: ~[int] = ~[];
    while divisor <= num::sqrt(n as float) as int {
        if n%divisor == 0 {
            factors = vec::append_one(factors, divisor);
            n = n / divisor;
            divisor = 2;
        } else {
            divisor += 1;
        }
    }
    factors = vec::append_one(factors, n);
    return factors;
}

fn main() {
    let factors = prime_factors(600851475143);
    let largest_prime_factor = *factors.last();
    println!("largest prime factor == {}", largest_prime_factor);
}
