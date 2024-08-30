import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    a1,a2,b1,b2 = map(int,input().split(" "))

    # on the first round:
    # a1 b1
    # a1 b2
    # a2 b1
    # a2 b2
    s = 0
    if a1>=b1 and a2>=b2 and not (a1==b1 and a2==b2):
        s+=2
    if a1>=b2 and a2>=b1 and not (a1==b2 and a2==b1):
        s+=2
    print(s)