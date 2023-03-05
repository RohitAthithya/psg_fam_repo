import math
a=[]
b=[]
i1,j1=0,0
def primefactors(n):
   #even number divisible
   i1,j1=0,0
   while n % 2 == 0:
      a.append(2)
      n = n // 2
      i1=i1+1
    
   #n became odd
   for i in range(3,int(math.sqrt(n))+1,2):
     
      while (n % i == 0):
        
         n = n // i
         a.append(i)
         i1=i1+1
    
   if n > 2:
      a[i1].append(n)
      i1=i1+1
 
n = int(input("Enter the number for calculating the prime factors :\n"))
primefactors(n)
print(a)