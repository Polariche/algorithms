import sys
inputs = sys.stdin.readlines()

n = int(inputs[0])
arr = [list(map(int, input.split())) for input in inputs[1:]]
# plz forgive me
cost = [[1001 if i==0 or j==0 or i==n-1 or j==n-1 else arr[i][j]+arr[i-1][j]+arr[i+1][j]+arr[i][j-1]+arr[i][j+1] for j in range(n)] for i in range(n)]

def pick(i,j):
    cost[i+1][j]+=1001
    cost[i-1][j]+=1001
    cost[i][j]+=1001
    cost[i][j-1]+=1001
    cost[i][j+1]+=1001
    cost[i-1][j-1]+=1001
    cost[i+1][j-1]+=1001
    cost[i-1][j+1]+=1001
    cost[i+1][j+1]+=1001

    if i>1:
        cost[i-2][j]+=1001
    if i<n-2:
        cost[i+2][j]+=1001
    if j>1:
        cost[i][j-2]+=1001
    if j<n-2:
        cost[i][j+2]+=1001

def unpick(i,j):
    cost[i+1][j]-=1001
    cost[i-1][j]-=1001
    cost[i][j]-=1001
    cost[i][j-1]-=1001
    cost[i][j+1]-=1001
    cost[i-1][j-1]-=1001
    cost[i+1][j-1]-=1001
    cost[i-1][j+1]-=1001
    cost[i+1][j+1]-=1001

    if i>1:
        cost[i-2][j]-=1001
    if i<n-2:
        cost[i+2][j]-=1001
    if j>1:
        cost[i][j-2]-=1001
    if j<n-2:
        cost[i][j+2]-=1001


def foo(s, depth):
    res = 3003
    if depth == 0:
        return 0
    for t in range(s, n*n):
        i,j = t//n, t%n
        if cost[i][j] < 1001:
            c = cost[i][j]
            #print(i, j, c)
            pick(i,j)
            res = min(res, c+foo(t+1, depth-1))
            unpick(i,j)
    return res

print(foo(0, 3))