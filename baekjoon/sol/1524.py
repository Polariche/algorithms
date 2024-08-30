import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    input()
    n,m = map(int, input().split(" "))
    a = list(map(int, input().split(" ")))
    b = list(map(int, input().split(" ")))

    warriors = [(i, 1) for i in a] + [(i, 0) for i in b]
    warriors = sorted(warriors)

    print('B' if warriors[-1][1] == 0 else 'S')