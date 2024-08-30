import sys
from collections import deque 
inputs = sys.stdin.readlines()
w,h = map(int, inputs[0].split())

arr = [list(map(int, input.split())) for input in inputs[1:]]
visited = [[False for _ in range(w+2)] for _ in range(h+2) ]

q = deque()
q2 = deque()
ans = 0

temp = 0
interior = True

for x in range(1,w+1):
    for y in range(1,h+1):
        q2.append((x,y))

while q or q2:
    if q:
        x,y = q.popleft()
    else:
        x,y = q2.popleft()
        if visited[y][x]:
            continue

    if 1<=x<=w and 1<=y<=h and arr[y-1][x-1]:
        continue
    
    visited[y][x] = True

    if y%2:
        nexts = [(x+1,y), (x-1,y), (x, y+1), (x+1, y+1), (x,y-1), (x+1,y-1)]
    else:
        nexts = [(x+1,y), (x-1,y), (x, y+1), (x-1, y+1), (x-1,y-1), (x,y-1)]

    for nx, ny in nexts:
        if 0<=nx<=w+1 and 0<=ny<=h+1 and not visited[ny][nx]:
            if 1<=nx<=w and 1<=ny<=h and arr[ny-1][nx-1]:
                temp+=1
                continue
            visited[ny][nx] = True
            q.append((nx,ny))

            if 0==nx or nx==w+1 or 0==ny or ny==h+1:
                interior=False

    if not q:
        if interior == False:
            ans += temp
        interior = True
        temp = 0

print(ans)