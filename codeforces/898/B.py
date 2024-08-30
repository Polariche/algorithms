import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())
    a = map(int, input().split(" "))

    cnt = [0 for _ in range(10)]
    mult = 1

    min_idx = 10
    for b in a:
        if b != 0:
            mult *= b
        cnt[b] += 1
        min_idx = min(b, min_idx)
    
    if cnt[0] == 0:
        print(mult // min_idx * (min_idx+1))
    elif cnt[0] == 1:
        print(mult)
    elif cnt[0] > 1:
        print(0)
