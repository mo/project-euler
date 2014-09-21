#
#  In this file, there are code present for solving this problem using
#  several different approaches. The first ones were two slow to be
#  valid solution (Project EULER says that it should be possible to
#  find an algorithm that solves the problem in less than 60 secs).
#
#
#  In the end, method number five ended up solving this problem in
#  0.024 secs which is really nice seeing as how the first three
#  attempts could not solve the problem even if they ran overnight.
#
#  
#  Note: It might also be interesting to look at the corresponding
#        sequence (the number of unique paths through an NxN grid)
#		 in Sloane's integer sequence dictionary:
# 
#        http://www.research.att.com/~njas/sequences/?q=2%2C6%2C20%2C70%2C252%2C924%2C3432%2C12870%2C48620&language=english&go=Search


import time

def number_of_bits_set(n):
	bits_set = 0
	while (n):
		bits_set += 1
		n &= n - 1
	return bits_set

def number_of_bits_set_2(n):
	bits_set = 0
	while (n):
		bits_set += n & 1
		n >>= 1
	return bits_set

def is_valid_path_bitcount_test(n, gridSize):
	if number_of_bits_set(n) == gridSize:
		return True
	return False

def is_valid_path_custom(n, gridSize):
	smallest_int_representing_a_valid_path = 2**gridSize - 1 # int with the lowest "gridSize" bits all set
	if n < smallest_int_representing_a_valid_path:
		return False;
	bits_set = 0
	for k in xrange(0, 2 * gridSize):
		bits_set += n & 1
		n >>= 1
		if bits_set > gridSize:
			return False
	return bits_set == gridSize
	
def is_valid_path(n, gridSize):	
	return is_valid_path_custom(n, gridSize)
		
def unit_tests():
	for x in xrange(1, 1500):
		assert number_of_bits_set(x) == number_of_bits_set_2(x)
	for gridSize in xrange(1, 7):
		for x in xrange(1, 2**gridSize):
			assert is_valid_path_bitcount_test(x, gridSize) == is_valid_path_custom(x, gridSize)

def number_of_possible_routes(gridSize):
	valid_path_count = 0
	for x in xrange(1, 2 ** (gridSize * 2)):
		if is_valid_path(x, gridSize):
			valid_path_count += 1
	return valid_path_count

def solve_problem_using_approach_one(maxGridSize):
	unit_tests()
	print "Looking for solution using approach one... for grid sizes up to", maxGridSize
	for x in xrange(1, maxGridSize + 1):
		print "time is now", time.localtime(), x, number_of_possible_routes(x)






#
# functions for my second attempt at solving this problem
#

def next_path(path):
	for index in xrange(1, len(path) + 1):
		i = len(path) - index
		if path[i] < len(path):
			path[i] += 1
			for ii in xrange(i + 1, len(path)):
				path[ii] = path[i]
			return True
	return False

def path_count(gridSize):
	count = 0	
	path = [0 for x in xrange(0, gridSize)] # the first path
	while True:
		#print path
		count += 1
		if not next_path(path):
			break;
	return count

def solve_problem_using_approach_two(maxGridSize):
	print "Looking for solution using approach two... for grid sizes up to", maxGridSize
	for n in xrange(1, maxGridSize + 1):
		print "time is now", time.localtime(), "gridSize ==", n, "has", path_count(n), "paths"






#
# functions for my third attempt at solving this problem
#

def sum(start, stop, func):
	sum = 0
	for x in xrange(start, stop + 1):
		sum += func(x)
	return sum

def level_sum(level, start_value, level_count):
	if level == 1:
		return sum(start_value, level_count, lambda a: 1)
	return sum(start_value, level_count, lambda a: level_sum(level - 1, a, level_count))

def solve_problem_using_approach_three(maxGridSize):
	print "Looking for solution using approach three... for grid sizes up to", maxGridSize
	for x in xrange(1, maxGridSize + 1):
		print "time is now", time.localtime(), x, level_sum(x, 0, x)





#
# functions for my fourth attempt at solving this problem
#

def factorial(n):
	if n == 0:
		return 1
	return n * factorial(n - 1)

def binomial_coefficient(n, k):
	return factorial(n) / (factorial(k) * factorial(n - k))

def path_count_using_binomial_sum(gridSize):
	return sum(0, gridSize, lambda k: binomial_coefficient(gridSize, k)**2)

def solve_problem_using_approach_four(maxGridSize):
	print "Looking for solution using approach four... for grid sizes up to", maxGridSize
	for x in xrange(1, maxGridSize + 1):
		print "time is now", time.localtime(), x, path_count_using_binomial_sum(x)




#
# functions for my fifth attempt at solving this problem
#
# ********
#
# Here is a detailed explanation of the thinking that lead me
# to this particular solution:
#
# While traversing the grid from top-left to down-right you
# make a series of choices where you go either DOWN or RIGHT.
# Since backtracking is not allowed, you can never move UP or LEFT.
# Therefore, the path you take through the grid can be described
# by a sequence of "n" R's and "n" D's (where R means RIGHT etc).
# Note that to reach the down-right part of an NxN grid it's necessary
# to move RIGHT exactly N times and also DOWN exactly N times.
#
# Moving straight along the top edge of the a 5x5 grid and then straight
# down would be represented by the sequence:
#
# 			RRRRRDDDDD
#
# Moving in a zig zag pattern across the diagonal of the grid would
# be repesented by one of the sequences:
#
#			RDRDRDRDRD  or  DRDRDRDRDR
#
# So basically each sequence of exactly N R's and also N D's will
# represent a path through an NxN grid, and at the same time each path
# through a NxN grid will be represented by exactly one such sequence.
#
# Thus, what we want to know is "In how many ways can be re-order a
# sequence of N R's and N D's". The answer goes back to basic
# combinatorics.
#
# In general X objects can be arranged in factorial(X) ways because
# first you choose then object which is supposed to go first and at that
# time you have X objects to choose from, after that you choose the
# object that should go after the first object and at this time you
# have only X-1 choices because you can't choose the already choosen
# object again. And thus you end up with X * (X - 1) * (X - 2) * ...
# ... * 1 = X!
#
# However, when we re-arrange a sequence of R'd and D's then each R is
# equivalent to each other R and thus if we change the order of the
# first two R's in this sequence:
#
#			RRRDDDRRDD
#
# Then we would still have the same sequence. If instead of N R's and
# N D's we had any set of 2*N unique objects then the numbers of ways
# they could be ordered would be factorial(2*N) but since the R's are
# all equivalent we need to disregard all the combinations where just
# one R is swapped with another R.
#
# Now if we think about only the subset of R's inside the sequence,
# they can under the same logic be re-arranged in factorial(N) ways
# because we know that the number of R's is exactly N. The same goes
# for the D's, there is factorial(N) ways to re-arrange the D's without
# ending up with a new different path.
#
# For every equivalent re-arrangement of the R's we can also put the D's
# into factorial(N) different orders without ending up with a new path.
# This means that, for example, in the sequence:
#
#			RRRDDDRRDD
# ...we can actually re-arrange the R's in factorial(5) ways while
# still representing the same path. Similarly, we can re-arrange the D's
# in factorial(5) ways. If we are allowed to swap R's with other R's and
# also swap D's with other D's then we can actually re-order this
# sequence in factorial(5)*factorial(5) different ways while the
# sequence still represents the exact same path.
#
# So there is factorial(2*N) different ways to re-order the R's and D's
# but out of those orderings we know that factorial(N)*factorial(N) are
# just "dummy orders" which represent the same path through the grid.
#
# Consequencely, the number of unique paths through the grid must be:
# 
# 			factorial(2*N) / (factorial(N) * factorial(N))
#
# This is implemented below and it works like a charm!
#

def path_count_combinatorial(gridSize):
	return factorial(2 * gridSize) / (factorial(gridSize) * factorial(gridSize))

def solve_problem_using_approach_five(maxGridSize):
	print "Looking for solution using approach five... for grid sizes up to", maxGridSize
	for x in xrange(1, maxGridSize + 1):
		print "time is now", time.localtime(), x, path_count_combinatorial(x)






#
# main program
#

solve_problem_using_approach_one(8)
solve_problem_using_approach_two(9)
solve_problem_using_approach_three(9)
solve_problem_using_approach_four(25)
solve_problem_using_approach_five(25)

print "the answer is", path_count_combinatorial(20)


