import sys
input = sys.stdin.readline

n = int(input())

t = list(map(int, input().split(" ")))

total = sum(t) + (len(t)-1) * 8
print(total//24, total%24, sep=' ')