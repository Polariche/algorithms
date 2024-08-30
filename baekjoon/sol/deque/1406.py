from collections import deque
import sys

input = lambda: sys.stdin.readline().strip()

s = input()
n = int(input())

left=deque(s)
right=deque([])

for i in range(n):
    cmd = input()
    if cmd == "L":
        if len(left)>0:
            right.appendleft(left.pop())
    elif cmd == "D":
        if len(right)>0:
            left.append(right.popleft())
    elif cmd == "B":
        if len(left)>0:
            left.pop()
    else:
        x = cmd.split(" ")[1]
        left.append(x)

print("".join(list(left)+list(right)))