package main

import "fmt"

func main() {
	var prevprev = 1
	var prev = 2
	var sum = 2
	for {
		var current = prevprev + prev
		if current >= 4000000 {
			break
		}
		if current%2 == 0 {
			sum += current
		}
		prevprev = prev
		prev = current
	}
	fmt.Printf("sum == %v\n", sum)
}
