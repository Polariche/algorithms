import sys
from collections import deque

n, m = map(int, sys.stdin.readline().strip().split(" "))

visited = [abs(m-n)+1 for _ in range(100001)]
visited[n] = 0

q = deque([n])
ans = abs(m-n)
while q:
    c = q.popleft()

    if c == m:
        ans = visited[c]
        break

    for c_ in [c-1,c+1,2*c]:
        if c_ >= 0 and c_ <= 100000:
            
            if visited[c]+1 < visited[c_]:
                q.append(c_)
                visited[c_] = visited[c]+1

print(ans)