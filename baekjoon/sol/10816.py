import sys

ips = sys.stdin.readlines()
n = int(ips[0].strip())
cards = map(int, ips[1].strip().split(" "))
m = int(ips[2].strip())
quests = map(int, ips[3].strip().split(" "))


d = dict()
for c in cards:
    try:
        d[c] += 1
    except KeyError:
        d[c] = 1

ans = []
for q in quests:
    try:
        ans.append(d[q])
    except KeyError:
        ans.append(0)

print(' '.join(map(str, ans)))