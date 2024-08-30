import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
verts = []
for _ in range(n):
    x,y = map(int, input().split(" "))
    verts.append((x,y))

f = (0,0)

ccw = lambda a,b,f: (a[0]-f[0])*(b[1]-f[1]) - (a[1]-f[1])*(b[0]-f[0])

def cmp(a,b):
    d = ccw(a,b,f)
    if d==0:
        return - ((a[0]-f[0])*(a[0]-f[0]) + (a[1]-f[1])*(a[1]-f[1]) - (b[1]-f[1])*(b[1]-f[1]) - (b[0]-f[0])*(b[0]-f[0]))
    else:
        return d
    

from functools import cmp_to_key

verts = list(reversed(sorted(verts, key=cmp_to_key(cmp))))
hull = []

print(verts)
while verts:
    v = verts.pop()
    if len(hull) >= 2:
        c = ccw(hull[-1],v,hull[-2])
        print(v, c)
        if c >= 0:
            hull.pop()
    hull.append(v)

print(len(hull))