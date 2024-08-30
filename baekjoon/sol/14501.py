import sys
input = sys.stdin.readline

N = int(input())
T = [0 for _ in range(N)]
P = [0 for _ in range(N)]
dp = [0 for _ in range(N)]
for i in range(N):
    T[i], P[i] = map(int, input().split(" "))
for i in range(N-1,-1,-1):
    j = i+T[i]
    if j>N:
        if i+1<N:
            dp[i] = dp[i+1]
    elif j==N:
        if j>i+1:
            dp[i] = max(dp[i+1], P[i])
        else:
            dp[i] = P[i]
    else: 
        dp[i] = max(dp[i+1], dp[j]+P[i])
print(dp[0])