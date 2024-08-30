import sys
import math 
input = sys.stdin.readline

T = int(input())


M = int(math.pow(10,9)+7)
for _ in range(T):
    n,k = map(int,input().split(" "))
    a = list(map(int, input().split(" ")))
    
    s = 0
    
    ones = 0
    zeros = 0

    for b in a:
        if b==1:
            ones+=1
        else:
            zeros+=1
    for i in range(max((k+1)//2, k-zeros), min(k, ones)+1):
        res = math.comb(ones, i)
        if zeros > 0:
            res *= math.comb(zeros, k-i)
        s = int(s + res)%M

    print(s)
