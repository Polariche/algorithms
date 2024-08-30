import sys
input = sys.stdin.readline

a,b = input().split(" ")

mx = max(len(a),len(b))
a = int(a); b = int(b)

stk = []

for i in range(mx):
    stk.append(a%10 + b%10)
    a = a//10
    b = b//10

    if a==0 and b==0:
        break

print(''.join([str(stk[i]) for i in range(len(stk)-1, -1, -1)]))