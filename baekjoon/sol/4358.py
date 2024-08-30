import sys
inputs = sys.stdin.readlines()

cnt = dict() 
total = 0

for input in inputs:
    try:
        cnt[input] += 1
    except KeyError:
        cnt[input] = 1
    total += 1

cnt = sorted([(k,v) for k,v in cnt.items()])

for t in cnt:
    k,v = t
    print(f"{k.strip()} {v/total*100:.4f}")