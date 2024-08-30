n = int(input())
a=n
for i in range(2,n):
    if n%i==0:
        a=i
        break
    elif i*i>n:
        break
print(n-n//a)