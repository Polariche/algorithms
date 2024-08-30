import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    score = 0
    a = [list(input().strip()) for _ in range(10)]
    for i in range(10):
        for j in range(10):
            if a[i][j] == 'X':
                score += min(i,j,9-i,9-j)+1
    print(score)