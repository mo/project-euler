fn sum_even_fib_less_than(max: int) -> int {
    let mut prevprev = 1i;
    let mut prev = 2i;
    let mut sum = 2i;
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
