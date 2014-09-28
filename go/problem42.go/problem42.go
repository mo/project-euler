package main

import "fmt"
import "io/ioutil"
import "strings"

func WordNumber(word string) int {
	var wordNumber = 0
	for i := 0; i < len(word); i++ {
		wordNumber += int(word[i]) - 64
	}
	return wordNumber
}

func IsTriangleNumber(num int) bool {
	var n = 0
	var currentTriangleNumber = 0
	for {
		n += 1
		currentTriangleNumber += n
		if currentTriangleNumber > num {
			return false
		} else if num == currentTriangleNumber {
			return true
		}
	}
}

func main() {
	var wordData, err = ioutil.ReadFile("../../data/p042_words.txt")
	if err != nil {
		panic(err)
	}

	var words = strings.Split(string(wordData), ",")
	for i := 0; i < len(words); i++ {
		words[i] = strings.Trim(words[i], "\"")
	}

	var triangleWords = 0
	for i := 0; i < len(words); i++ {
		if IsTriangleNumber(WordNumber(words[i])) {
			triangleWords += 1
		}
	}

	fmt.Printf("answer == %v\n", triangleWords)
}
