fn sum_of_nums_less_than_n_divisible_by_3_and_5(upper_limit: int) -> int {
    let mut sum = 0i;
    let mut i = 1i;
    while i < upper_limit {
        if i % 3 == 0 || i % 5 == 0 {
            sum += i;
        }
        i += 1;
    }
    return sum;
}

pub fn main() {
    let answer = sum_of_nums_less_than_n_divisible_by_3_and_5(1000);
    println!("answer == {}", answer);
}

#[cfg(test)]
mod test {
    use super::sum_of_nums_less_than_n_divisible_by_3_and_5;

    #[test]
    fn correct_answer() {
        assert_eq!(sum_of_nums_less_than_n_divisible_by_3_and_5(10), 23);
    }
}
