import sys
from collections import deque

ip = sys.stdin.readlines()

r,c = map(int, ip[0].strip().split(" "))
m = [list(t.strip()) for t in ip[1:]]

ans = [[-1 for _ in range(c)] for _ in range(r)]

q = deque()
x, y = -1, -1
for i,a in enumerate(m):
    for j,b in enumerate(a):
        if b == 'S':
            q.append((i,j))
            ans[i][j] = 0
        elif b == 'D':
            x=i
            y=j

for i,a in enumerate(m):
    for j,b in enumerate(a):
        if b == '*':
            q.append((i,j))

# https://wookcode.tistory.com/167
mov = [(1,0), (-1,0), (0,-1), (0,1)]

while q:
    i,j = q.popleft()

    for di,dj in mov:
        if 0 <= i+di < r and 0<= j+dj < c:
            if m[i][j] == 'S' and m[i+di][j+dj] == 'D':
                ans[i+di][j+dj] = ans[i][j] + 1
                q.clear()
                break

            elif m[i][j] == 'S' and m[i+di][j+dj] == '.':
                m[i+di][j+dj] = 'S'
                ans[i+di][j+dj] = ans[i][j] + 1
                q.append((i+di, j+dj))

            elif m[i][j] == '*' and (m[i+di][j+dj] == '.' or m[i+di][j+dj] == 'S'):
                m[i+di][j+dj] = '*'
                q.append((i+di, j+dj))

if ans[x][y] > 0:
    print(ans[x][y])
else:
    print("KAKTUS")