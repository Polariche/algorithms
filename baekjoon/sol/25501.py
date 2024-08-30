import sys
input = sys.stdin.readline

n = int(input())

def pal(st, s,e):
    if s>=e:
        return 1, 1
    if st[s]!=st[e]:
        return 0, 1
    res, cnt = pal(st, s+1,e-1)
    return res, cnt+1

for _ in range(n):
    st = input().strip()
    print(*pal(st, 0, len(st)-1))