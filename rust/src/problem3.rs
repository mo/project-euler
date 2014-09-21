/* Run tests with;
 *
 *   rustc --test problem3.rs ; ./problem3
 *
 */

fn prime_factors(mut n: int) -> Vec<int> {
    let mut divisor = 2;
    let mut factors: Vec<int> = Vec::new();
    while divisor <= (n as f64).sqrt() as int {
        if n%divisor == 0 {
            factors.push(divisor);
            n = n / divisor;
            divisor = 2;
        } else {
            divisor += 1;
        }
    }
    factors.push(n);
    return factors;
}

pub fn main() {
    let factors = prime_factors(600851475143);
    let largest_prime_factor = factors.last().unwrap();
    println!("largest prime factor == {}", largest_prime_factor);
}

#[cfg(test)]
mod test {
    use super::prime_factors;

    #[test]
    fn correct_answer() {
        let factors = prime_factors(600851475143);
        let expected_answer = 6857;
        let computed_answer: int = *factors.last().unwrap();
        assert_eq!(computed_answer, expected_answer);
    }
}
