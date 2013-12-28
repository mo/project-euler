package main

import (
	"math"
	"testing"
)

func IsPrime(num int) bool {
	if num == 1 {
		return false
	}
	if num == 2 {
		return true
	}
	for i := 2; i <= int(math.Sqrt(float64(num))); i++ {
		if num%i == 0 {
			return false
		}
	}
	return true
}

func Product(ints []int) (product int) {
	product = 1
	for _, val := range ints {
		product *= val
	}
	return product
}

func AllPrimes(ints []int) bool {
	for _, val := range ints {
		if !IsPrime(val) {
			return false
		}
	}
	return true
}

func IntsEquals(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i, v := range a {
		if v != b[i] {
			return false
		}
	}
	return true
}

func tc(t *testing.T, num int, expected_factors []int) {
	var factors = PrimeFactors(num)
	if Product(factors) != num || !AllPrimes(factors) || !IntsEquals(factors, expected_factors) {
		t.Error("bug")
	}
}

func TestSanity(t *testing.T) {
	tc(t, 2, []int{2})
	tc(t, 3, []int{3})
	tc(t, 4, []int{2, 2})
	tc(t, 19, []int{19})
	tc(t, 49, []int{7, 7})
	tc(t, 3141592, []int{2, 2, 2, 392699})
	tc(t, 9341592, []int{2, 2, 2, 3, 13, 79, 379})
	tc(t, 6469693230, []int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
}
