import sys
input = sys.stdin.readline

st = input().strip()
ops = {'*', '+', '-', '/'}

op_stk = []
for c in st:
    if c == '*' or c == '/':
        while op_stk:
            if op_stk[-1] == '*' or op_stk[-1] =='/':
                print(op_stk.pop(), end='')
            else:
                break
        op_stk.append(c)
    elif c == '+' or c == '-':
        while op_stk:
            if op_stk[-1] !='(':
                print(op_stk.pop(), end='')
            else:
                break
        op_stk.append(c)
    elif c == '(':
        op_stk.append(c)
    elif c == ')':
        while op_stk:
            if op_stk[-1] !='(':
                print(op_stk.pop(), end='')
            else:
                break
        op_stk.pop()
    else:
        print(c, end='')

while op_stk:
    print(op_stk.pop(),end='')
