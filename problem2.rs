fn main() {
    let mut prevprev = 1;
    let mut prev = 2;
    let mut sum = 2;
    loop {
        let current = prevprev + prev;
        if (current % 2 == 0) { sum += current; }
        if (current >= 4000000) { break; }
        prevprev = prev;
        prev = current;
    }
    println!("sum == {}", sum);
}
