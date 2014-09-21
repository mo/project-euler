def sum_of_digits(number):
	number = str(number)
	sum = 0
	for digit in number:
		sum += int(digit)
	return sum

def test_it(n):
	print n, "sum==", sum_of_digits(n)

test_it(2 ** 1000)
