N = int(input())

def is_num(c):
    c = ord(c)
    return ord('0') <= c and ord('9') >= c

numlist = []
for _ in range(N):
    st = input()+'n'

    num = -1
    for c in st:
        if is_num(c):
            if num < 0:
                num=0
            num = num*10+int(c)
        else:
            if num > -1:
                numlist.append(num)
            num = -1

for num in sorted(numlist):
    print(num)