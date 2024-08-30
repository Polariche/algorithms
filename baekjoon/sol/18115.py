from collections import deque
n = int(input())
actions = list(map(int, input().split(" ")))

b = list(reversed(range(1,n+1)))
q = deque()
while actions:
    a = actions.pop()
    if a == 1:
        q.appendleft(b.pop())
    elif a == 2:
        q.rotate(-1)
        q.appendleft(b.pop())
        q.rotate(1)
    elif a == 3:
        q.append(b.pop())

print(' '.join(map(str, q)))