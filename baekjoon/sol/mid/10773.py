K = int(input())

li = []
s = 0
for _ in range(K):
    n = int(input())

    if n>0:
        s+=n
        li.append(n)
    else:
        s-=li.pop()

print(s)