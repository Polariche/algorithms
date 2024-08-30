from collections import deque 

n,k = map(int, input().split(" "))

q = deque(range(1,n+1))

ans = []

while q:
    q.rotate(-k)
    ans.append(q.pop())

print("<" + ", ".join(map(str, ans)) + ">")
