import sys
input = lambda: sys.stdin.readline().strip()

T = int(input())
for _ in range(T):
    n = int(input())
    d = dict()

    for _ in range(n):
        _, wear = input().split(" ")
        try:
            d[wear] += 1
        except KeyError:
            d[wear] = 1
    
    s = 1
    for v in d.values():
        s *= v+1
    print(s-1)
    