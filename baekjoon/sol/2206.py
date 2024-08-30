import sys
import math
from collections import deque 
inputs = sys.stdin.readlines()

n,m = map(int, inputs[0].split(" "))
a = [[int(i) for i in input.strip()] for input in inputs[1:]]
time = [[[math.inf, math.inf] for j in range(m)] for i in range(n)]

time[0][0][0] = 1

q = deque([(0,0,0)])
diff = [(1,0),(-1,0),(0,1),(0,-1)]

while q:
    x,y,z = q.popleft()
    t = time[x][y][z]
    
    if x==n-1 and y==m-1:
        break

    for dx,dy in diff:
        if 0<=x+dx<n and 0<=y+dy<m:
            if a[x+dx][y+dy] == 0:
                if time[x+dx][y+dy][z] == math.inf:
                    time[x+dx][y+dy][z] = t+1
                    q.append((x+dx, y+dy, z))

            elif z<1:
                if time[x+dx][y+dy][z+1] == math.inf:
                    time[x+dx][y+dy][z+1] = t+1
                    q.append((x+dx, y+dy, z+1))

ans = min(time[-1][-1])
if ans > m*n:
    print(-1)
else:
    print(ans)