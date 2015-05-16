fn is_palindrome(num: i64) -> bool {
    let num_str = num.to_string();
    let chars_to_check = num_str.len()/2;
    let mut iter = num_str.as_bytes().iter().take(chars_to_check);
    let mut rev_iter = num_str.as_bytes().iter().rev().take(chars_to_check);
    // HACK: In future rust versions, this can probably be replaced by
    // "return iter == rev_iter"
    loop {
        match (iter.next(), rev_iter.next()) {
            (Some(x), Some(y)) => if x != y { return false },
            _ => return true,
        }
    }
}

fn largest_palindrome_product(max_digits: u32) -> i64 {
    let mut highest_found = 0;
    for a in 1..10i64.pow(max_digits) {
        for b in 1..10i64.pow(max_digits) {
            let prod = a*b;
            if prod > highest_found && is_palindrome(prod) {
                highest_found = prod
            }
        }
    }
    return highest_found
}

pub fn main() {
    let answer = largest_palindrome_product(2);
    if answer != 9009 {
        panic!("error: wrong answer");
    }
    let answer = largest_palindrome_product(3);
    println!("largest palindrome made from the product of two 3-digit integers is {}", answer);
}

#[cfg(test)]
mod test {
    use super::{is_palindrome, largest_palindrome_product};

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
}
