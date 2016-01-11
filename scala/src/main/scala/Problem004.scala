object Problem004 {

  def isPalindrome(str: String): Boolean = {
    (str zip str.reverse).slice(0, str.length / 2).forall { case (a,b) => a == b }
  }

  def largestPalindrome(digits: Int): Int = {
    val lowest = math.pow(10, digits-1).toInt
    val highest = math.pow(10, digits).toInt - 1
    val products = for { a <- lowest to highest; b <- lowest to highest } yield a * b
    products.sortWith(_ > _).find(prod => isPalindrome(prod.toString)).get
  }

  def main(args: Array[String]) {
    require(largestPalindrome(2) == 9009)
    println(largestPalindrome(3))
  }

}