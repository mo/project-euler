package main

import (
	"fmt"
	"math"
)

func PrimeFactors(num int) (factors []int) {
	divisor := 2
	for divisor <= int(math.Sqrt(float64(num))) {
		if num%divisor == 0 {
			factors = append(factors, divisor)
			num = num / divisor
			divisor = 2
		} else {
			divisor++
		}
	}
	factors = append(factors, num)
	return factors
}

func main() {
	var problem_factors = PrimeFactors(600851475143)
	fmt.Printf("largest prime factor == %v\n", problem_factors[len(problem_factors)-1])
}
