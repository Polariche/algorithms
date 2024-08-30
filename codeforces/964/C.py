import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    n,s,m = map(int,input().split(" "))
    last = 0
    res = False
    for _ in range(n):
        a,b = map(int, input().split(" "))
        if a-last >= s:
            res = True
        last = b
    if not res:
        if m-last >= s:
            res=True
    
    print("YES" if res else "NO")