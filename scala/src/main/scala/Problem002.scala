object Problem002 {

  def main(args: Array[String]) {
    // fib(0) == 1 i.e. the literal 1 outside of scanLeft call
    // fib(1) == 1 i.e. just the scanLeft z=1 by itself
    // fib(2) == 1 + fib(0) == 2
    // fib(3) == 1 + fib(0) + fib(1) == 3
    // fib(4) == 1 + fib(0) + fib(1) + fib(2) == 5
    // fib(5) == 1 + fib(0) + fib(1) + fib(2) + fib(3) == 8
    // fib(6) == 1 + fib(0) + fib(1) + fib(2) + fib(3) + fib(4) == 13
    // fib(7) == 1 + fib(0) + fib(1) + fib(2) + fib(3) + fib(4) + fib(5) == 21
    // ...
    def fib: Stream[Int] = 1 #:: fib.scanLeft(1){_ + _}
    println(Iterator.from(1).map(fib).takeWhile(n => n < 4000000).filter(i => i % 2 == 0).sum)
  }

}
