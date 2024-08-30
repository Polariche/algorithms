from collections import deque

n = int(input())
li = deque(range(n,0,-1))

while len(li) > 1:
    li.pop()
    li.appendleft(li.pop())

print(li.pop())