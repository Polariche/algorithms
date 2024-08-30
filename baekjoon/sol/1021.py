import sys
from collections import deque
n,m = map(int, sys.stdin.readline().strip().split(" "))

inds = map(int, sys.stdin.readline().strip().split(" "))


q = deque(range(1,n+1))
s = 0

for ind in inds:
    a = -1
    for i, t in enumerate(q):
        if ind == t:
            a = i
            break
    if a < len(q)-a:
        q.rotate(-a)
        s+=a
        q.popleft()
    else:
        q.rotate(len(q)-a)
        s+=len(q)-a
        q.popleft()
        
print(s)