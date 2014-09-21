extern crate num;

use num::bigint::BigUint;

fn to_biguint(num_str: &str) -> BigUint {
    return from_str::<BigUint>(num_str).unwrap();
}

fn factorial(num: BigUint) -> BigUint {
    if num == to_biguint("1") {
        return to_biguint("1")
    }
    return num * factorial(num - to_biguint("1"));
}

fn sum_of_digits(num: BigUint) -> uint {
    let mut sum = 0;
    for ch in num.to_string().as_slice().chars() {
        sum += std::char::to_digit(ch, 10).unwrap();
    }
    return sum
}

pub fn main() {
    let answer = sum_of_digits(factorial(to_biguint("100")));
    println!("answer = {}", answer);
}

#[cfg(test)]
mod test {

    use super::{factorial, sum_of_digits, to_biguint};

    #[test]
    fn test_factorial() {
        assert_eq!(factorial(to_biguint("1")), to_biguint("1"));
        assert_eq!(factorial(to_biguint("2")), to_biguint("2"));
        assert_eq!(factorial(to_biguint("3")), to_biguint("6"));
        assert_eq!(factorial(to_biguint("4")), to_biguint("24"));
        assert_eq!(factorial(to_biguint("5")), to_biguint("120"));
        assert_eq!(factorial(to_biguint("10")), to_biguint("3628800"));
        assert_eq!(factorial(to_biguint("101")), to_biguint("9425947759838359420851623124482936749562312794702543768327889353416977599316221476503087861591808346911623490003549599583369706302603264000000000000000000000000"));
    }

    #[test]
    fn test_sum_of_digits() {
        assert_eq!(sum_of_digits(to_biguint("0")), 0);
        assert_eq!(sum_of_digits(to_biguint("1")), 1);
        assert_eq!(sum_of_digits(to_biguint("11")), 2);
        assert_eq!(sum_of_digits(to_biguint("120")), 3);
        assert_eq!(sum_of_digits(to_biguint("123")), 6);
        assert_eq!(sum_of_digits(to_biguint("4321")), 10);
        assert_eq!(sum_of_digits(to_biguint("6227020800")), 27);
    }

    #[test]
    fn test_example() {
        assert_eq!(factorial(to_biguint("10")), to_biguint("3628800"));
        assert_eq!(sum_of_digits(factorial(to_biguint("10"))), 27);
    }
}
