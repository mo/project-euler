fn main() {
    println("1: 1");
    println("2: 2");
    let mut second_last = 1;
    let mut last = 2;
    let mut i = 3;
    let mut sum = 2;
    let mut current = 0;
    while (current < 4000000) {
        current = second_last + last;
        println!("{}: {}", i, current);
        if (current % 2 == 0) {
            sum += current;
        }
        second_last = last;
        last = current;
        i += 1;
    }
    println!("sum == {}", sum);
}
