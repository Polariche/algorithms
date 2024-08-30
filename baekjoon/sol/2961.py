import sys
input = sys.stdin.readline

N = int(input())
a = []
for _ in range(N):
    a.append(tuple(map(int, input().split(" "))))


S = [1 for _ in range(1024)]
B = [0 for _ in range(1024)]

# O(N2^N)
# acceptable since 1<=N<=10
for i in range(N):
    bit = 1<<i
    for j in range(1,2**N):
        if bit & j:
            S[j] *= a[i][0]
            B[j] += a[i][1]

print(min([abs(S[i]-B[i])  for i in range(1,2**N)]))