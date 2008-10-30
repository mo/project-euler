#
# This solution finishes in about 11 seconds on my machine.
#
# Answer was: 76576500 which is the 12375'th triangle number
# This number has has 576 divisors.
#

import math

MINIMUM_DIVISOR_COUNT = 500
divisor_count_cache = {}

def triangle_number(n):
	return (n + 1) * n / 2
# unit tests
assert triangle_number(7) == 28

def divisor_count_slow_reference_implementation(n):
	divisorCount = 0
	for d in xrange(1, n + 1):
		if n % d == 0:
			divisorCount += 1
	return divisorCount

# returns the set of all integers that divides "n"
def divisor_count(n):
	divisorCount = 0
	for d in xrange(1,  int(math.sqrt(n)) + 1):
		if n % d == 0:
			if d*d == n:
				# dont count both 2 and 4/2==2 when computing divisor_count(4) etc
				divisorCount += 1
			else:
				# count d and n/d (since loop ends at sqrt(n) we're not gonna get to n/d anyway
				divisorCount += 2
	return divisorCount

# unit tests
for n in xrange(1, 500):
	print "for n ==", n, "  assert divisor_count(n) ==", divisor_count(n), "==", divisor_count_slow_reference_implementation(n), "== divisor_count_slow_reference_implementation(n)"
	assert divisor_count(n) == divisor_count_slow_reference_implementation(n)

def do_it():
	div_count = 0
	number = 1	
	while div_count < MINIMUM_DIVISOR_COUNT:
		number += 1
		tn = triangle_number(number)
		div_count = divisor_count(tn)
		print "triangle number", number, "is", tn, "and has", div_count, "divisors"
	print
	print
	print "triangle number", number, "is", tn, "and has more than", MINIMUM_DIVISOR_COUNT, "divisors"

def test_it(n):
	print n, divisor_count(n)

for x in xrange(1, 20):
	test_it(x)

do_it()

