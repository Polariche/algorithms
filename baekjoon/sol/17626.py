import sys
input = sys.stdin.readline
n = int(input())

a = [0 if i**0.5%1 else 1 for i in range(n+1)]
def sol(n):
    if a[n] == 1:
        return 1
    min = 4
    for i in range(1,int(n**0.5)+1):
        if a[n-i*i]==1:
            return 2
        for j in range(1,int((n-i*i)**0.5)+1):
            if a[n-i*i-j*j]==1:
                min = 3
    return min
print(sol(n))
        