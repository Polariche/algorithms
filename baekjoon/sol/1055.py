import sys
inputs = sys.stdin.readlines()

s = inputs[0].strip()
pat = inputs[1].strip()
repeat = int(inputs[2].strip())
n,m = map(int, inputs[3].strip().split(" "))

cnt = 0
for p in pat:
    if p == '$':
        cnt += 1

len(pat)+(len(s)-1)*cnt
