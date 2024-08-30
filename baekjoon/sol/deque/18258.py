from collections import deque
import sys 
q = deque()
n = int(sys.stdin.readline())

for _ in range(n):
    a = sys.stdin.readline().strip().split(" ")
    func=a[0]
    if func=="push": 
        q.appendleft(a[1])
    if func=="pop": 
        if len(q)>0:
            print(q.pop())
        else:
            print(-1)
    if func=="size":
        print(len(q))
    if func=="empty":
        print(0 if len(q)>0 else 1)
    if func=="front":
        if len(q)>0:
            print(q[-1])
        else:
            print(-1)
    if func=="back":
        if len(q)>0:
            print(q[0])
        else:
            print(-1)    