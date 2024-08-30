import sys
input = sys.stdin.readline

n = int(input())
x = list(map(int, input().split(" ")))
xi = sorted(range(n), key=lambda i: x[i])

t = [-1 for _ in range(n)]

prev = -1
uniq = 0
for i,j in enumerate(xi):
    if i>0:
        if x[j] > x[xi[i-1]]:
            uniq+=1
    t[j] = uniq
    prev = x[j]

print(*t, sep=' ')
