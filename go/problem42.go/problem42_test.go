package main

import (
	"testing"
)

func TestWordValueSky(t *testing.T) {
	got := WordNumber("SKY")
	expected := 55
	if got != expected {
		t.Errorf("got %v expected %v", got, expected)
	}
}

var triangleNumberTests = []struct {
	number   int  // input
	expected bool // expected result
}{
	{1, true},
	{2, false},
	{3, true},
	{4, false},
	{5, false},
	{6, true},
	{7, false},
	{8, false},
	{9, false},
	{10, true},
	{11, false},

	{14, false},
	{15, true},
	{16, false},

	{20, false},
	{21, true},
	{22, false},

	{28, true},
	{36, true},
	{45, true},
	{55, true},
}

func TestIsTriangleNumber(t *testing.T) {
	for _, testdata := range triangleNumberTests {
		actual := IsTriangleNumber(testdata.number)
		if actual != testdata.expected {
			t.Errorf("IsTriangleNumber(%v): expected %v, actual %v", testdata.number, testdata.expected, actual)
		}
	}
}
