import sys
input = sys.stdin.readline

N,K = map(int,input().split(" "))

dp = [[-1 if j>0 else 0 for j in range(K+1)] for _ in range(N+1)]

for n in range(N):
    w,v = map(int, input().split(" "))
    
    for k in range(K+1):
        if dp[n][k] != -1:
            dp[n+1][k] = max(dp[n+1][k], dp[n][k])
            if k+w<=K:
                dp[n+1][k+w] = max(dp[n][k]+v, dp[n+1][k+w])

print(max(dp[-1]))