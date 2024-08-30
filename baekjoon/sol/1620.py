import sys
n,m=map(int, sys.stdin.readline().strip().split(" "))

dtp = ["" for _ in range(n+1)]
ptd = dict()

for i in range(1,n+1):
    pkmn = sys.stdin.readline().strip()
    ptd[pkmn] = i
    dtp[i] = pkmn

for _ in range(m):
    st = sys.stdin.readline().strip()
    if st.isdigit():
        print(dtp[int(st)])
    else:
        print(ptd[st])