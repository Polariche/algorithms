m,n=map(int, input().split(" "))
bools = list([True for i in range(0,n+1)])
bools[0]=bools[1]=False
p=2
while p*p<=n:
    if bools[p]:
        for q in range(p*p,n+1,p):
            bools[q]=False
    p+=1

print('\n'.join(map(str, [p for p in range(m,n+1) if bools[p]])))