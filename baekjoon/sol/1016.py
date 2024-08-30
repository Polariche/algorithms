import sys 
import math
n,m = map(int, sys.stdin.readline().strip().split(" "))
m_rt = int(math.sqrt(m))

li = [True for _ in range(n,m+1)]
s = m+1-n

for p in range(2,m_rt+1):
    p2 = p*p
    for t in range(p2*(n//p2+(n%p2>0)), m+1, p2):
        if li[t-n]:
            li[t-n]=False
            s-=1

print(s)