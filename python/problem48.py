def power_sum(n):
	sum = 0
	for x in xrange(1, n + 1):
		sum += x**x
	return sum

answer = str(power_sum(1000))
print "answer ==", answer[len(answer)-10:len(answer)]
