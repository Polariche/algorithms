import sys
import math

input = sys.stdin.readline

T = int(input())
dp = []
for _ in range(T):
    l, r = map(int, input().split(" "))

    a = [ math.floor(math.log(i,3))+1 for i in range(r,l-1,-1)]
    s = a.pop()*2
    print(s+sum(a))
