import sys
from collections import deque 
input = sys.stdin.readline

n,m = map(int, input().split(" "))
trusts = [[] for _ in range(n)]

for _ in range(m):
    a,b = map(int, input().split(" "))
    a-=1;b-=1

    trusts[b].append(a)

def bfs(s):
    q = deque([s])
    cnt = 0

    v = [False]*n
    v[s] = True

    while q:
        a = q.popleft()
        for b in trusts[a]:
            if not v[b]:
                v[b] = True
                q.append(b)
                cnt += 1
    return cnt

res = []
mx = -1
ans = []
for i in range(n):
    res.append(bfs(i))
    if res[i] > mx:
        mx=res[i]
        ans.clear()
    if res[i] == mx:
        ans.append(i+1)

print(*ans, sep=' ')
