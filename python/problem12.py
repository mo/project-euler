#
# This is a ridiculously slow solution. Also the cache is pointless (stupid)
# as-is.
#
# Running this code until the answer is printed takes between 8 and 18 hours.
#
# Answer was: 76576500 which is the 12375'th triangle number
# This number has has 576 divisors.
#



import math

MINIMUM_DIVISOR_COUNT = 500


# returns the Nth triangle number
def triangle_number_old_slow(n):
	sum = 0
	for i in xrange(1,n + 1):
		sum += i
	return sum

def triangle_number(n):
	return (n + 1) * n / 2

# unit tests
assert triangle_number(7) == 28

# returns the set of all integers that divides "n"
def divisors(n):
	return filter(lambda d: n % d == 0, xrange(1, n + 1))

def divisor_count_for_triangle_number(n):
	cached_value = divisor_count_cache.get(n, -1)
	if cached_value != -1:
		return cached_value
	divisor_count_cache[n] = len(divisors(triangle_number(n)))
	return divisor_count_for_triangle_number(n)

divisor_count_cache = {}
div_count = 0
number = 1
while div_count < MINIMUM_DIVISOR_COUNT:
	number += 1
	div_count = divisor_count_for_triangle_number(number)
	print "triangle number", number, "is", triangle_number(number), "and has", div_count, "divisors"
print
print
print "triangle number", number, "is", triangle_number(number), "and has more than", MINIMUM_DIVISOR_COUNT, "divisors"
