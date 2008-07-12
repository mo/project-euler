

def factorial(n)
  return 1 if n == 1
  return n * factorial(n-1)
end

fac100 = factorial(100)

sum = 0
fac100.to_s.split('').each { |digit| sum += digit.to_i }
print "sum==", sum, "\n"

print "sum_again==", fac100.to_s.split('').map {|c| c.to_i}.inject{|sum,k| sum+k}

