# Correct answer was:
# the 4782th fibonacci number which is 1070066266382758936764980584457396885083683896632151665013235203375314520604694040621889147582489792657804694888177591957484336466672569959512996030461262748092482186144069433051234774442750273781753087579391666192149259186759553966422837148943113074699503439547001985432609723067290192870526447243726117715821825548491120525013201478612965931381792235559657452039506137551467837543229119602129934048260706175397706847068202895486902666185435124521900369480641357447470911707619766945691070098024393439617474103736912503231365532164773697023167755051595173518460579954919410967778373229665796581646513903488154256310184224190259846088000110186255550245493937113651657039447629584714548523425950428582425306083544435428212611008992863795048006894330309773217834864543113205765659868456288616808718693835297350643986297640660000723562917905207051164077614812491885830945940566688339109350944456576357666151619317753792891661581327159616877487983821820492520348473874384736771934512787029218636250627816
#
#  * the dumb recursive solution took way too long (recomputing and discarding all the time)
#  * the closed form formula failed because python choked with floating point overflow or something like that for fibonacci number 1475 and above
#  * finally, just caching the computed values and reusing those for a not recursive computation worked great (it took around 25 secs to compute the answer using this method)
#

import math

def fibonacci_recursive(n):
	if n == 1:
		return 1
	if n == 2:
		return 1
	return fibonacci_recursive(n - 2) + fibonacci_recursive(n - 1)

fibonacci_cache = {1: 1, 2: 1}
def fibonacci_recursive_cached(n):
	cached_fibonacci_value = fibonacci_cache.get(n, -1)
	if cached_fibonacci_value != -1:
		return cached_fibonacci_value
	computed_fibonacci = fibonacci_recursive_cached(n - 2) + fibonacci_recursive_cached(n - 1)
	fibonacci_cache[n] = computed_fibonacci
	return computed_fibonacci

golden_ratio = (1 + math.sqrt(5)) / 2
def fibonacci_binet(n):
	# compute fibonacci number using binet's formula (see Wikipedia)
	return int((golden_ratio**n - (1 - golden_ratio)**n) / math.sqrt(5))

def fibonacci(n):
	return fibonacci_recursive_cached(n)

def fibonacci_unittest():
	for n in xrange(1, 30):
		assert fibonacci_recursive(n) == fibonacci_binet(n)
		assert fibonacci_binet(n) == fibonacci_recursive_cached(n)

#
# main program starts here
#

fibonacci_unittest()

n = 0
fibonacci_n = 0
while len(str(fibonacci_n)) < 1000:
	n += 1
	fibonacci_n = fibonacci(n)
	print n, fibonacci_n
