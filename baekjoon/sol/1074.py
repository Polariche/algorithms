import sys
input = sys.stdin.readline
n,r,c = map(int,input().split(" "))

pow_n=1
for i in range(n):
    pow_n*=2

idx = 0
for i in range(n):
    pow_n=pow_n//2
    a,b = r//pow_n, c//pow_n
    idx_block = pow_n*pow_n

    idx += idx_block*(2*a+b)

    r,c = r%pow_n, c%pow_n
print(idx)