import sys
inputs = sys.stdin.readlines()

n = int(inputs[0])
m = int(inputs[1])
adj = [list(map(int, input.split())) for input in inputs[2:-1]]
order = [i-1 for i in list(map(int, inputs[-1].split()))]

"""
5
5
0 1 0 1 1
1 0 1 1 0
0 1 0 0 0
1 1 0 0 0
1 0 0 0 0
5 3 2 3 5
"""
"""
YES
"""

# if adj[i][k] and adj[k][j], then adj[i][j]

leaders = [i for i in range(n)]

def find(i):
    if leaders[i]==i:
        return i
    leaders[i] = find(leaders[i])
    return leaders[i]

def union(i,j):
    i = find(i)
    j = find(j)
    p = min(i,j)    # let the smallest person be the leader
    leaders[i]=p
    leaders[j]=p
    
for i in range(n):
    for j in range(n):
        if adj[i][j]:
            union(i,j)

ans = "YES"           # we can do it
prev = find(order[0])
for i in range(1,m):
    next = find(order[i])
    if prev!=next:
        ans = "NO"
    prev = next
print(ans)
