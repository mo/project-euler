
def isPrime(n)
  return true if (n == 2)
  return false if (n == 1 or n % 2 == 0)
  for divisor in 3..Math.sqrt(n).floor
    return false if n % divisor == 0
  end
  return true
end

def nthPrime(n)
  number = 1
  primesFound = 0
  while (true)
    primesFound += 1 if isPrime(number)
    return number if primesFound == n
    number += 1
  end
end

def sumOfPrimesBelow(n)
  sum = 0
  for number in 1..n
    sum += number if isPrime(number)          
  end
  return sum
end

p sumOfPrimesBelow(1000000)




