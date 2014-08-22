fn main() {
    let mut prevprev = 1i;
    let mut prev = 2i;
    let mut sum = 2i;
    loop {
        let current = prevprev + prev;
        if current >= 4000000 { break; }
        if current % 2 == 0 { sum += current; }
        prevprev = prev;
        prev = current;
    }
    println!("sum == {}", sum);
}
