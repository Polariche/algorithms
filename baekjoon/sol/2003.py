import sys
input = lambda: sys.stdin.readline().strip()

n,m = map(int, input().split(" "))
a = [0] + list(map(int, input().split(" ")))

for i in range(1,n+1):
    a[i] += a[i-1]

ans = 0
i=1
j=0
while i<n+1:
    s = a[i]-a[j]
    if s == m:
        ans+=1
        i+=1
    elif s > m:
        j+=1
    elif s < m:
        i+=1

print(ans)