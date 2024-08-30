import math
a,b,h = map(int,input().split(" "))
a,b=min(a,b),max(a,b)

if a==b:
    print(-1)
else:

    # H-h:H = a:b
    # H*a = (H-h)*b
    # H*a = H*b - h*b
    # H*(b-a) = h*b
    # H = h*b/(b-a)

    H = h*b/(b-a)
    print(math.pi * (H**2+b**2-(H-h)**2-a**2))