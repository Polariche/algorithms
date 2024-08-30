n = int(input())
x = dict()              # dict for counting
for _ in range(n):
    ext = input().split(".")[1]     # get the word after .
    if ext not in x.keys():
        x[ext] = 1
    else:
        x[ext] += 1
x = sorted([(k,v) for k,v in x.items()], key=lambda x: x[0])    # sort per value
for k,v in x:
    print(k, v)