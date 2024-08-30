import sys
input = sys.stdin.readline

T = int(input())

def solve(s,t):
    ans = []
    j=0
    for i in range(len(t)):
        if j >= len(s):
            return False, ''
        while not(s[j] == '?' or s[j]==t[i]):
            ans.append(s[j])
            j+=1
            if j>=len(s):
                return False, ''
        ans.append(t[i])
        j+=1
    if j<len(s):
        for r in s[j:]:
            if r == '?':
                ans.append('a')
            else:
                ans.append(r)
    return True, ''.join(ans)

for _ in range(T):
    s = input().strip()
    t = input().strip()

    arg1, arg2 = solve(s,t)
    if arg1:
        print("YES")
        print(arg2)
    else:
        print("NO")
    
        