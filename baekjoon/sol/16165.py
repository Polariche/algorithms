import sys
input = sys.stdin.readline

n,m=map(int,input().split(" "))
d0 = dict()
d1 = dict()

for _ in range(n):
    group = input()
    k=int(input())
    girls = []
    for _ in range(k):
        girl = input()
        d1[girl] = group
        girls.append(girl)
    d0[group] = sorted(girls)
    
for _ in range(m):
    quest = input()
    q = int(input())
    
    if q == 0:
        for girl in d0[quest]:
            print(girl)
    elif q == 1:
        print(d1[quest])