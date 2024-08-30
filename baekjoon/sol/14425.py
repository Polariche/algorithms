import sys
ips = sys.stdin.readlines()

n,m = map(int, ips[0].strip().split(" "))
s = set([ip.strip() for ip in ips[1:1+n]])
q = [ip.strip() for ip in ips[1+n:]]

a = 0

for p in q:
    if p in s:
        a+=1

print(a)