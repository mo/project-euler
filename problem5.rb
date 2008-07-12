def divByInts(n,ints)
  ints.each { |i|
    if n % i != 0  
      return false
    end
  }
  return true
end

magic = 2*2*2*2*3*3*5*7*11*13*17*19
print "magic==",magic,"\n"

for i in (1..20)
  if magic % i != 0
    print "i==",i,"\n"
  end
end

=begin
divisors = 1..20
for n in (1..1000000000)  
  if !divByInts(n,divisors)
    next
  end
  puts n
  $stdout.flush
end
=end

