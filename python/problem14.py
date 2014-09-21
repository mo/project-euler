

#
# This program takes like 1-2 mins to run on a 2.8GHz quad core (uses only one core ofc though)
#
# Obviously this program can be optimized by saving the computed length corresponding to each starting_number
# in an array and then using this cached value when comnputing the length of bigger starting_number values.
#

STARTING_NUMBER_UPPER_BOUND = 1000000

def collatz_sequence(n):
	if n == 1:
		return [1]
	elif n % 2 == 0:
		return [n] + collatz_sequence(n/2)	
	else:
		return [n] + collatz_sequence(3*n + 1)	

current_longest_sequence_starting_number = 0
current_longest_sequence_length = 0
for starting_number in xrange(1, STARTING_NUMBER_UPPER_BOUND):
	sequence_length = len(collatz_sequence(starting_number))
	if sequence_length > current_longest_sequence_length:
		current_longest_sequence_length = sequence_length
		current_longest_sequence_starting_number = starting_number

print "the longest collatz sequence with starting number under", STARTING_NUMBER_UPPER_BOUND, "is", current_longest_sequence_starting_number, "and that sequence has", current_longest_sequence_length, "elements"
