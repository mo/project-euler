package main

import "fmt"
import "strconv"
import "runtime"
import "math"

func IsPalindrome(num int) bool {
	num_str := strconv.FormatInt(int64(num), 10)
	num_str_len := len(num_str)
	for i := 0; i < num_str_len; i++ {
		if num_str[i] != num_str[num_str_len-i-1] {
			return false
		}
	}
	return true
}

func LargestPalindromicProduct(maxDigits int) int {
	highestFound := 0
	for a := 0; a < int(math.Pow10(maxDigits)); a++ {
		for b := 0; b < int(math.Pow10(maxDigits)); b++ {
			product := a * b
			if product > highestFound && IsPalindrome(product) {
				highestFound = product
			}
		}
	}
	return highestFound
}

func SourceLocation(skip int) string {
	_, file, line, ok := runtime.Caller(skip)
	if !ok {
		return "<error>"
	} else {
		return file + ":" + strconv.FormatInt(int64(line), 10)
	}
}

func AssertEq(actual bool, expected bool) {
	if actual != expected {
		fmt.Printf("sanity test failed at %v\n", SourceLocation(2))
		fmt.Printf("  actual: %v\n", actual)
		fmt.Printf("  expected: %v\n", expected)
	}
}

func AssertEqInt(actual int, expected int) {
	if actual != expected {
		fmt.Printf("sanity test failed at %v\n", SourceLocation(2))
		fmt.Printf("  actual: %v\n", actual)
		fmt.Printf("  expected: %v\n", expected)
	}
}

func RunSanityTest() {
	AssertEq(IsPalindrome(1), true)
	AssertEq(IsPalindrome(10), false)
	AssertEq(IsPalindrome(11), true)
	AssertEq(IsPalindrome(12), false)
	AssertEq(IsPalindrome(22), true)
	AssertEq(IsPalindrome(33), true)
	AssertEq(IsPalindrome(110), false)
	AssertEq(IsPalindrome(121), true)
	AssertEq(IsPalindrome(112), false)
	AssertEq(IsPalindrome(121), true)
	AssertEq(IsPalindrome(1111), true)
	AssertEq(IsPalindrome(1221), true)
	AssertEq(IsPalindrome(1231), false)
	AssertEqInt(LargestPalindromicProduct(2), 9009)
	AssertEqInt(LargestPalindromicProduct(3), 906609)
}

func main() {
	RunSanityTest()
	fmt.Printf("answer == %v\n", LargestPalindromicProduct(3))
}
