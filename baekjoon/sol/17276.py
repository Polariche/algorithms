import sys
input = sys.stdin.readline
from collections import deque
T = int(input())

for _ in range(T):
    n,d = map(int,input().split(" "))
    d = d//45
    a = []
    for _ in range(n):
        a.append(input().strip().split(" "))

    rings = []

    for i in range(n//2):
        q = [a[0+i][0+i], a[0+i][n//2], a[0+i][-1-i],
             a[n//2][-1-i],a[-1-i][-1-i],a[-1-i][n//2], 
             a[-1-i][0+i], a[n//2][0+i]]

        q = deque(q)
        q.rotate(d)
        a[0+i][0+i], a[0+i][n//2], a[0+i][-1-i], a[n//2][-1-i],a[-1-i][-1-i],a[-1-i][n//2], a[-1-i][0+i], a[n//2][0+i] = q

    for b in a:
        print(' '.join(b))