import sys
input = sys.stdin.readline

n = int(input())
children = [[] for _ in range(n)]

for _ in range(n-1):
    p,c,d = map(int, input().split(" "))
    children[p-1].append((c-1,d))

rads = [0 for _ in range(n)]
def compute(i, dist):
    cn = len(children[i])
    if cn==0:
        return dist
    elif cn==1:
        c = i
        original_dist = dist
        while cn==1:
            c,d = children[c][0]
            dist += d
            cn = len(children[c])
        res = compute(c,dist)
        rads[i] = res-original_dist
        return res
    
    ans = 0
    max2 = 0
    for c,d in children[i]:
        res = compute(c,dist+d)
        if ans<res:
            max2 = ans
            ans = res
        elif max2<res:
            max2 = res
    if max2 > 0:
        rads[i] = ans+max2-dist*2
    else:
        rads[i] = ans-dist

    return ans

a = compute(0, 0)
print(max(rads))