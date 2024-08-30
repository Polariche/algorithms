import sys
inputs = sys.stdin.readlines()

def cantor(n):
    if n==0:
        return '-'
    return cantor(n-1)+' '*(3**(n-1))+cantor(n-1)

for input in inputs:
    n = int(input)
    print(cantor(n))
    