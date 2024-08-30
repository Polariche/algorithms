import sys
ips = sys.stdin.readlines()


def read_time(s):
    return tuple(map(int,s.split(":")))

def cmp(t1, t2):
    if t1[0]==t2[0]:
        return t1[1] >= t2[1]
    else:
        return t1[0] >= t2[0]

s,e,q = map(read_time, ips[0].strip().split(" "))
spl = [ip.strip().split(" ") for ip in ips[1:]]
times = [read_time(sp[0]) for sp in spl]
names = [sp[1] for sp in spl]

p1 = set()
p2 = set()

for t,n in zip(times, names):
    if cmp(s, t):
        p1.add(n)
    elif cmp(t, e) and cmp(q, t):
        p2.add(n)

print(len(p1.intersection(p2)))