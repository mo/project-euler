

def fibonacci(n):
    if n == 1 or n == 0:
        return 1
    return fibonacci(n-1) + fibonacci(n-2)

special_sum = 0
i = 0
ith_fibonacci_number = fibonacci(i);
while ith_fibonacci_number < 1000000:
    if ith_fibonacci_number % 2 == 0:
        special_sum += ith_fibonacci_number
    i += 1
    ith_fibonacci_number = fibonacci(i);
    
print "special_sum ==", special_sum



