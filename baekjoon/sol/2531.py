import sys
input = sys.stdin.readline

n,d,k,c = map(int, input().split(" "))
a = []
for _ in range(n):
    a.append(int(input()))
a+=a
ans = 0
for i in range(n):
    ans = max(ans, len(set(a[i:i+k]+[c])))
print(ans)

