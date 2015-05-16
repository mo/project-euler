fn sum_even_fib_less_than(max: i64) -> i64 {
    let mut prevprev = 1;
    let mut prev = 2;
    let mut sum = 2;
    loop {
        let current = prevprev + prev;
        if current >= max { break; }
        if current % 2 == 0 { sum += current; }
        prevprev = prev;
        prev = current;
    }
    return sum;
}

pub fn main() {
    let answer = sum_even_fib_less_than(4000000);
    println!("answer == {}", answer);
}

#[cfg(test)]
mod test {
    use super::sum_even_fib_less_than;

    #[test]
    fn correct_answer() {
        assert_eq!(sum_even_fib_less_than(100), 44);
        assert_eq!(sum_even_fib_less_than(4000000), 4613732);
    }
}
