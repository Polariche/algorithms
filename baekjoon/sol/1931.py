import sys
import math
input = sys.stdin.readline

n = int(input())

k = set()
zeros = dict()
mintime = dict()

for _ in range(n):
    s,e = map(int,input().split(" "))
    
    if s not in k:
        k.add(s)
        zeros[s] = 0
        mintime[s] = math.inf
    if e>s:
        mintime[s] = min(e, mintime[s])
    elif e==s:
        zeros[s] += 1

k = sorted(list(k))
times = [(s,mintime[s]) for s in k]

occ_e = -1
cnt = 0
for s,e in times:
    if zeros[s]>0:
        if occ_e > s:
            cnt -= 1
        occ_e = s
        cnt += zeros[s]

    if mintime[s] == math.inf:
        continue
    
    if s >= occ_e and e>s:
        occ_e = e
        cnt += 1
    elif s < occ_e and e>s:
        occ_e = min(e, occ_e)
print(cnt)

