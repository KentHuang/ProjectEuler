MAX_LENGTH = 600


def BigNum(n):
  x = [0]*MAX_LENGTH
  ind = MAX_LENGTH-1
  while n > 0:
  	x[ind] = n%10
  	ind-=1
  	n = n/10
  return x


def BigSum(a,b):
  x = [0]*MAX_LENGTH
  carry = 0
  for i in range(MAX_LENGTH-1,-1,-1):
    x[i] = (a[i] + b[i] + carry)%10
    carry = (a[i] + b[i] + carry)/10
  return x


def bitShift(a, k):
  return a[k:] + [0]*k


def BigMult(a,b):
  x = [0]*MAX_LENGTH
  bits = 0
  for i in range(MAX_LENGTH-1,-1,-1):
    product = [0]*MAX_LENGTH
    carry = 0
    for j in range(MAX_LENGTH-1,-1,-1):
      product[j] = (b[i] * a[j] + carry)%10
      carry = (b[i] * a[j] + carry)/10
    x = BigSum(x, bitShift(product, bits))
    bits+=1
  return x


def BigFact(n):
  x = BigNum(2)
  for i in range(3,n+1):
    x = BigMult(x, BigNum(i))
  return x


# print BigFact(10)
x = BigFact(100)
print x
print sum(x)



