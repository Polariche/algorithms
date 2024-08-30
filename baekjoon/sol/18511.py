import sys
input = sys.stdin.readline

n,m = map(int,input().split(" "))
k = list(map(int, input().split(" ")))
k = sorted(k, reverse=True)

n_ = n
cnt = 0
while n_>0:
    n_ = n_//10
    cnt += 1

def foo(s, depth):
    if depth==0:
        if s<=n:
            return s
        else:
            return -1
    ans = s
    for t in k:
        b = foo(s*10 + t, depth-1)
        if b <=n:
            ans = max(ans, b)
    return ans

print(foo(0, cnt))
        
