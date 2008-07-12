


def isPrime(n)
  return true if (n == 2)
  return false if (n == 1 or n % 2 == 0)
  for divisor in 3..Math.sqrt(n).floor
    return false if n % divisor == 0
  end
  return true
end

def nthPrime(n)
  number = 1;
  primesFound = 0
  while (true)
    primesFound += 1 if isPrime(number)
    return number if primesFound == n
    number += 1
  end
end

=begin
for x in 1..30
  print x, "==", nthPrime(x), "\n"
end
=end
  
print "10001th prime is == ", nthPrime(10001), "\n"





