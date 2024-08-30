import sys
input = sys.stdin.readline

b=input().split("-")
c=[sum(map(int, t.split("+"))) for t in b]

print(sum(c[::2])-sum(c[1::2]))