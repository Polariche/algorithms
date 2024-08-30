import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    n = int(input())
    s = 0
    while n>0:
        s+=n%10
        n=n//10
    print(s)