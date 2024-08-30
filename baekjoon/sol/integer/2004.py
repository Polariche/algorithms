def cnt(x,y):   # count the number of y multiplied in x!
    # if x = 50, y=5
    # x! = 50*49*...*55*...*50*...      -> 10 '5's
    #    = 5^10*(10*9*...*...*1)*...
    # so, a += 10, x/= 5 then repeat for 10!
    a=0
    while x>0:
        a+=x//y
        x=x//y
    return a

n,m=input().split(" ")
n,m=int(n),int(m)

# (n m) = n!/m!(n-m)!
print(min(cnt(n,5)-cnt(m,5)-cnt(n-m,5),cnt(n,2)-cnt(m,2)-cnt(n-m,2)))