import sys
input = sys.stdin.readline

n = int(input())
tar = "abc"
for _ in range(n):
    st = list(input().strip())
    swapped = False
    ans="YES"
    for i in range(3):
        if st[i] != tar[i] and not swapped:
            swapped=True
            for j in range(i+1,3):
                if st[j]==tar[i]:
                    st[j]=st[i]
                    st[i]=tar[i]
                    break
        elif st[i] != tar[i] and swapped:
            ans = "NO"
            break

    print(ans)
