import sys
from collections import deque
input = sys.stdin.readline
n = int(input())
k = int(input())
a = []
for _ in range(n):
    a.append(int(input()))
a = deque(a)

"""
4
3
21
3
2
13
"""
"""
21 + 3 = 2 + 13
"""

ans = set()

def mult10(num):
    i=1
    while num>0:
        i*=10
        num=num//10
    return i

def make(num, depth):
    if depth == 0:
        ans.add(num)
        return
    len_a = len(a)
    for _ in range(len_a):
        b = a.popleft()
        make(num*mult10(b)+b, depth-1)
        a.append(b)

make(0, k)
print(len(ans))
        
