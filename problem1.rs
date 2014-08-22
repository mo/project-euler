fn main() {
    let mut sum = 0i;
    let mut i = 1i;
    while i < 1000 {
        if i % 3 == 0 || i % 5 == 0 {
            sum += i;
        }
        i += 1;
    }
    println!("sum == {}", sum);
}
