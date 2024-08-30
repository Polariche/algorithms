import sys
input = sys.stdin.readline

N = int(input())
for T in range(1,N+1):
    M = int(input())
    P = list(map(int, input().split(" ")))
    idx = sorted(list(range(1,13)), key=lambda i: P[i-1])

    max_idx = [-1 for _ in range(12)]
    mx = -1
    for i in range(11,-1,-1): 
        mx = max(mx, idx[i])
        max_idx[i] = mx

    profit = -1
    a = -1; b = -1
    for i in range(11):
        if P[i] > M:
            break
        if max_idx[i+1] < idx[i]:
            continue
        for j in range(11,i,-1):
            if idx[i]<idx[j]:
                a = idx[i]; b = idx[j]
                profit = (P[b-1]-P[a-1])*(M//P[a-1])
                break
        if profit>-1:
            break
    
    if profit>0:
        print(f"Case #{T}: {a} {b} {profit}")
    else:
        print(f"Case #{T}: IMPOSSIBLE")