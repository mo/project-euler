import math

number = 600851475143

known_divisors = []
possible_divisor = 2
while possible_divisor < math.sqrt(number):
	if (number % possible_divisor == 0):
		known_divisors.append(possible_divisor)
		number = number / possible_divisor
		if number == 1:
			break
		possible_divisor = 2
	possible_divisor += 1
print known_divisors
