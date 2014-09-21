
def is_palindrome(number):
	number = str(number)
	number_digits = len(number)
	for i in xrange(0, number_digits/2):
		if number[i] != number[number_digits-i-1]:
			return False
	return True

def test_it(n):
	print n, is_palindrome(n)

for x in xrange(0,1231):	
	test_it(x);

greatest_palindrome = 0
for x in xrange(100,999):
	for y in xrange(100,999):
		product = x * y
		if is_palindrome(product) and product > greatest_palindrome:
			greatest_palindrome = product

print greatest_palindrome
