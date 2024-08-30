import sys
input = sys.stdin.readline

n,m = map(int, input().split(" "))
p = [i for i in range(n)]

def find(i):
    if i==p[i]:
        return i
    p[i] = find(p[i])
    return p[i]

def union(i,j):
    i=find(i)
    j=find(j)
    k=min(i,j)
    p[i]=k
    p[j]=k

for _ in range(m):
    i,j=map(int,input().split(" "))
    i-=1; j-=1
    union(i,j)

for i in range(n):
    find(i)

print(len(set(p)))