package main

import "fmt"
import "math"

func isPrime(num int) bool {
	if num%2 == 0 {
		return num == 2
	}
	if num%3 == 0 {
		return num == 3
	}
	sqrt_num := int(math.Sqrt(float64(num)))
	for i := 6; i-1 <= sqrt_num; i += 6 {
		if num%(i-1) == 0 {
			return num == i-1
		}
		if (i+1) <= sqrt_num && num%(i+1) == 0 {
			return num == i+1
		}
	}
	return true
}

func sumOfPrimesBelow(limit int) int {
	var primeSum = 2
	for n := 3; n < limit; n += 2 {
		if isPrime(n) {
			primeSum += n
		}
	}
	return primeSum
}

func main() {
	var answer = sumOfPrimesBelow(2000000)
	fmt.Printf("answer == %v\n", answer)
}
