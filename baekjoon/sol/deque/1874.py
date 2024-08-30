import sys
n = int(sys.stdin.readline())
pt = 1

st = []
ans=[]
able=True
for _ in range(n):
    m = int(sys.stdin.readline())
    found=False
    for t in range(pt, m+1):
        st.append(t)
        ans.append("+")
        pt+=1

        if t == m: 
            found=True
            st.pop()
            ans.append("-")

    if not found:
        if st[-1] == m:
            st.pop()
            ans.append("-")
        else:
            able=False
            break

if able:
    for a in ans:
        print(a)
else:
    print("NO")

