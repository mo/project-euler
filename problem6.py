


print "Hello world"

sum = 0
sum_of_squares = 0

for x in range(1,101):
    sum += x
    sum_of_squares += x*x

print "sum ==", sum
print "sum of squares ==", sum_of_squares
print "square of the sum ==", sum*sum
print "square of the sum - sum of the squares ==", sum*sum - sum_of_squares

