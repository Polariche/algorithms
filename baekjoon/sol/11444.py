import sys
n = int(sys.stdin.readline())
M = 1000000007

#   n  0  1  2  3  4  5  6   7   8
# F(n) 0  1  1  2  3  5  8  13  21 ..

# https://howudong.tistory.com/300
# F(n) =   F(n-1) +   F(n-2)
#      = 2*F(n-2) +   F(n-3)
#      = 3*F(n-3) + 2*F(n-4)
#      = 5*F(n-4) + 3*F(n-5)
#      = 8*F(n-5) + 5*F(n-6)
# ...
#      = F(k+1)F(n-k) + F(k)F(n-k-1)

# n=2k
# F(2k)   = F(k+1)F(k) + F(k)F(k-1)
#         = F(k){F(k+1)+F(k-1)}

# n=2k+1
# F(2k+1) = F(k+1)F(k+1) + F(k)F(k)
#         = F(k+1)^2 + F(k)^2


from collections import deque
q = deque([n])
stk = []
v = set()
while q:
    n = q.popleft()
    m = n//2
    
    if n<2:
        continue

    if m+1 not in v:
        q.append(m+1)
        v.add(m+1)
    if m not in v:
        q.append(m)
        v.add(m)

    if n%2 == 0:
        if m-1 not in v:
            q.append(m-1)
            v.add(m-1)

    stk.append(n)

fib = {0:0, 1:1, 2:1}
while stk:
    n = stk.pop()
    m = n//2
    if n%2 == 0:
        fib[n] = fib[m]*((fib[m+1]+fib[m-1])%M)%M
    else:
        fib[n] = ((fib[m+1]*fib[m+1])%M + (fib[m]*fib[m])%M)%M

print(fib[n])