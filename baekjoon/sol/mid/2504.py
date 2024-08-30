st = input()
m = 1
s = 0
stk = []
leaf = True
for c in st:
    if c == '(':
        m *= 2
        stk.append(c)
        leaf=True

    elif c == '[':
        m *= 3
        stk.append(c)
        leaf=True

    elif c == ')':
        if len(stk) == 0:
            s = 0
            break
        if stk.pop() != '(':
            s = 0
            break
        if leaf:
            s += m
        m /= 2
        leaf=False
    
    elif c == ']':
        if len(stk) == 0:
            s = 0
            break
        if stk.pop() != '[':
            s = 0
            break
        if leaf:
            s += m
        m /= 3
        leaf=False

if len(stk) > 0:
    s = 0
print(int(s))