special_sum = 0
n_minus_1 = n_minus_2 = 1
fib_n = 0
while fib_n < 1000000:
	fib_n, n_minus_1, n_minus_2 = n_minus_1, n_minus_2, n_minus_1 + n_minus_2
	if fib_n % 2 == 0: special_sum += fib_n
print(special_sum)
