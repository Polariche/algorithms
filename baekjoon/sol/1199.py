import sys
inputs = sys.stdin.readlines()
sys.setrecursionlimit(100000)

"""
TC: https://www.acmicpc.net/board/view/61009
4
0 1 0 1
1 0 1 2
0 1 0 1
1 2 1 0
"""
"""
4
0 1 2 1
1 0 1 2
2 1 0 1
1 2 1 0
"""

n = int(inputs[0])
adj = [list(map(int, input.split(" "))) for input in inputs[1:]]
sums = [sum(adj[i]) for i in range(n)]
target = sum(sums)//2

stk = []
def dfs(x, y, l):
    # x : current node
    # y : start node
    # l : stk pointer
    cur_stk = len(stk)
    if x==y and cur_stk > l:
        stk.append(x+1)
        return y

    sums[x] -= 1; stk.append(x+1)
    for z in range(n):
        if not adj[x][z]:
            continue
        sums[z] -= 1; adj[x][z] -= 1; adj[z][x] -= 1
        if dfs(z, y, l) == y:
            break
        sums[z] += 1; adj[x][z] += 1; adj[z][x] += 1; stk.pop()


    return y



cont = True
for s in sums:
    if s%2 == 1:
        cont = False

if not cont:
    print(-1)
else:
    start = 0
    substk = []
    while sums[start] > 0:
        dfs(start,start,len(stk))
        stk.pop()
        for i in range(len(stk)-1, -1, -1):
            if sums[stk[i]-1]:
                start = stk[i]-1
                for j in range(i, len(stk)):
                    substk.append(stk.pop())
                break

    while substk:
        stk.append(substk.pop())

    stk.append(1)
    print(*stk)