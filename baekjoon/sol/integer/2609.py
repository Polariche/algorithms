a,b = map(int, input().split(' '))
r=1
for i in range(min(a,b),1,-1):      # finding min multiplier
    if a%i==0 and b%i==0:
        r=i
        break
print(r)
print(int(a/r)*b)                   # max multiplier = a*b/(min mult)