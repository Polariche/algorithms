import sys
inputs = sys.stdin.readlines()
n,m = map(int, inputs[0].split(" "))
a = [[1 if t=='#' else 0 for t in list(input)] for input in inputs[1:]]
at = [[a[j][i] for j in range(n)] for i in range(m)]

sum_a = [sum(a[i]) for i in range(n)]
sum_at = [sum(at[j]) for j in range(m)]

def find(sum_arr):
    first_mx = 1
    second_mx = 1

    first_mx_i = -1
    second_mx_i = -1
    for i,s in enumerate(sum_arr):
        if first_mx < s:
            second_mx = first_mx
            second_mx_i = first_mx_i
            first_mx = s
            first_mx_i = i
        elif second_mx < s:
            second_mx = s
            second_mx_i = i
    if first_mx>second_mx:
        return 1 if second_mx_i>first_mx_i else -1
    else:
        return 0

d1, d2 = find(sum_a), find(sum_at)
if d1<0:
    print("UP")
elif d1>0:
    print("DOWN")
elif d2<0:
    print("LEFT")
elif d2>0:
    print("RIGHT")
        
