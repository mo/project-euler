number = 600851475143

for divisor in xrange(2,number):
	if (number % divisor == 0):
		print divisor, " is a divisor"
		number = number / divisor
		print "new number is", number
