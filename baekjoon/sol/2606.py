import sys
input = sys.stdin.readline
n = int(input())
m = int(input())
e = [set() for _ in range(n)]
for _ in range(m):
    i,j = map(int,input().split(" "))
    e[i-1].add(j-1)
    e[j-1].add(i-1)


q = [0]
v = [False for _ in range(n)]
v[0] = True
cnt=0
while q:
    a = q.pop()
    for b in e[a]:
        if not v[b]:
            v[b] = True
            q.append(b)
            cnt+=1
print(cnt)