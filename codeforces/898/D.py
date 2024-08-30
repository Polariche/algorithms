import sys
input = sys.stdin.readline


T = int(input())
for _ in range(T):
    n,k = map(int, input().split(" "))
    st = input().strip()

    erase = 0
    op = 0

    for c in st:
        if erase>0:
            erase -= 1
            continue
        if c=='B':
            erase = k-1
            op += 1
    print(op)