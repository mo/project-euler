object Problem001 {

  def solve(limit: Int): Int = {
    (1 to limit-1).filter(i => i % 3 == 0 || i % 5 == 0).sum
  }

  def main(args: Array[String]): Unit = {
    require(solve(10) == 23)
    println(solve(1000))
  }

}
