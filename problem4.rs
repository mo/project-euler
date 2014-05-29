use std::num;

fn is_palindrome(num: int) -> bool {
    let num_str = num.to_str();
    let num_str_len = num_str.len();
    for i in range(0, num_str_len/2) {
        if num_str.as_slice().char_at(i) != num_str.as_slice().char_at(num_str_len-i-1) {
            return false;
        }
    }
    return true;
}

fn largest_palindrome_product(max_digits: uint) -> int {
    let mut highest_found = 0;
    for a in range(1, num::pow(10, max_digits)) {
        for b in range(1, num::pow(10, max_digits)) {
            let prod = a*b;
            if prod > highest_found && is_palindrome(prod) {
                highest_found = prod
            }
        }
    }
    return highest_found
}

#[test]
fn tests() {
    assert_eq!(is_palindrome(0), true);
    assert_eq!(is_palindrome(1), true);
    assert_eq!(is_palindrome(10), false);
    assert_eq!(is_palindrome(11), true);
    assert_eq!(is_palindrome(12), false);
    assert_eq!(is_palindrome(22), true);
    assert_eq!(is_palindrome(33), true);
    assert_eq!(is_palindrome(333), true);
    assert_eq!(is_palindrome(131), true);
    assert_eq!(is_palindrome(1331), true);
    assert_eq!(is_palindrome(1231), false);
    assert_eq!(largest_palindrome_product(2), 9009);
}

fn main() {
    let answer = largest_palindrome_product(2);
    if answer != 9009 {
        fail!("error: wrong answer");
    }
    let answer = largest_palindrome_product(3);
    println!("largest palindrome made from the product of two 3-digit integers is {}", answer);
}
