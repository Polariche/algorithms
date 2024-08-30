import sys
from collections import deque
inputs = sys.stdin.readlines()
T = len(inputs)-1

def permute(i, v, depth, s, k):
    if depth==0:
        print(*[s[j] for j in range(1,k+1) if v[j]], sep=' ')
        return

    for j in range(i+1, k+1):
        v[j] = True
        permute(j, v, depth-1, s, k)
        v[j] = False

for t,input in enumerate(inputs[:-1]):
    input = input.strip().split(" ")
    k = int(input[0])
    s = list(map(int, input))
    
    v = [False for _ in range(k+1)]
    permute(0, v, 6, s, k)
    if t<T-1:
        print()