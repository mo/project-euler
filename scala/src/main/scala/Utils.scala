import scala.collection.mutable.ListBuffer

object Utils {

  def median(values: Seq[Long]): Double = {
    if (values.length % 2 == 1) {
      values.sorted.drop(values.length / 2).head
    } else {
      val (lower, upper) = values.splitAt(values.size / 2)
      (lower.last + upper.head) / 2.0
    }
  }

  def benchmark(description: String, iterations: Int = 5)(code: => Unit): Unit = {
    // Run once without measuring so the JIT compiler can do its thing
    // Use -XX:+PrintCompilation to make sure "code" is heavy enough
    code

    val measuredTimes = ListBuffer[Long]()
    for (_ <- 1 to iterations) {
      val start = System.nanoTime()
      code
      val nanoSecondsTaken = System.nanoTime() - start
      measuredTimes.append(nanoSecondsTaken)
    }
    val averageNanoSeconds = measuredTimes.sum / measuredTimes.length
    val medianNanoSeconds = median(measuredTimes)
    val averageStr = if (averageNanoSeconds > 1000000) {
      averageNanoSeconds / 1000000 + " ms"
    } else {
      averageNanoSeconds + " nano seconds"
    }
    val medianStr = if (medianNanoSeconds > 1000000) {
      medianNanoSeconds / 1000000 + " ms"
    } else {
      medianNanoSeconds + " nano seconds"
    }
    println(s"$description: average $averageStr, median $medianStr")
  }

}
