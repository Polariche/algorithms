import sys
import math
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    n,x = map(int,input().split(" "))

    a = list(map(int,input().split(" ")))
    a = sorted(a, reverse=True)

    sm = sum(a)

    # maximize h s.t
    # x >= sum([min(0,h-b) for b in a])

    # in other words:
    # c = [b for in a if b<h]
    # x >= h*(len(a)-len(c)) - sum(c)
    # (x+sum(c)) / (len(a)-len(c)) >= h

    val = [a[0]]
    cnt = [1]
    
    for b in a[1:]:
        if val[-1] != b:
            val.append(b)
            cnt.append(1)
        else:
            cnt[-1]+=1
    
    bar = n
    for i in range(len(val)):
        v,c = val[i], cnt[i]
        if x >= v*bar-sm:
            break
        sm -= v*c
        bar -= c

    print((x+sm)//bar)
