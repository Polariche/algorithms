import sys
import math
input = sys.stdin.readline

n,m,k = map(int, input().split(" "))
li = [0 for _ in range(n)]



# segtree example 1.
# for n = 4
# 1     / 2      3     / 4      5      6      7
# [0:4] / [0:2], [2:4] / [0:1], [1:2], [2:3], [3:4]
# 1+2+4 = 7

# segtree example 2.
# for n = 5
# 1     / 2      3     / 4      5      6      7     / 8      9
# [0:5] / [0:3], [3:5] / [0:2], [2:3], [3:4], [4:5] / [0:1], [1:2]
# 1+2+4+2 = 9


# m = (s+e+1)//2
# parent / left    right
# i      / 2*i     2*i+1
# [s:e]  / [s:m]   [m:e]

# counting ..
# 2**(ceil(log2(n))+1) -1

segtree_maxlength = 2**(math.ceil(math.log2(n))+1)-1
segtree = [0 for _ in range(segtree_maxlength)]

def modify(idx, val):
    s = 0
    e = n
    tree_i = 1
    old_val = li[idx]
    li[idx] = val

    while e>=s+1:
        segtree[tree_i-1] += val - old_val
        m = (e+s+1)//2
        if e==m:
            break
        if m>idx:
            tree_i = tree_i*2
            e = m
        else:
            tree_i = tree_i*2+1
            s = m

def getsum(s,e, i, target_s, target_e):
    if target_s>e or target_e<=s:
        return 0
    if target_s<=s and e<=target_e:
        return segtree[i-1]
    if s+1==e:
        return 0
    m = (s+e+1)//2
    return getsum(s,m, 2*i, target_s, target_e) + getsum(m,e, 2*i+1, target_s, target_e)
        
        
for i in range(n):
    a = int(input())
    modify(i, a)
    li[i] = a


for _ in range(m+k):
    a,b,c = map(int, input().split(" "))

    if a == 1:
        modify(b-1,c)
    elif a == 2:
        print(getsum(0,n,1,b-1,c))