import sys
inputs = sys.stdin.readlines()

n,m=map(int,inputs[0].split(" "))
a = list(list(map(int, input.split(" "))) for input in inputs[1:])

dist = [[-1 if a[i][j]>0 else 0 for j in range(m)]for i in range(n)]

start = (-1,-1)
for i in range(n):
    for j in range(m):
        if a[i][j]==2:
            start = (i,j)
            dist[i][j] = 0
            break

from collections import deque
q = deque([start])

diffs = [(-1,0),(1,0),(0,-1),(0,1)]

while q:
    i,j = q.popleft()
    for di,dj in diffs:
        if 0<=i+di<n and 0<=j+dj<m:
            if dist[i+di][j+dj] == -1:
                dist[i+di][j+dj] = dist[i][j] + 1
                q.append((i+di,j+dj))

for a in dist:
    print(*a, sep=' ')