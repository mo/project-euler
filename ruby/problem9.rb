

def isInt(x)
  return x.to_i == x
end

if false
for a in 1..1000
  for b in 1..1000
    c = Math.sqrt(a**2 + b**2)
    if isInt(c) and a+b+c == 1000
      print "a,b,c==", a,",",b,",",c.to_i, "\n"
    end
  end
end
end

print 200*375*425

















