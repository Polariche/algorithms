a=list(map(int,list(input())))          
b=[0 for _ in range((len(a)+2)//3)]     # 3 digits in binary = 1 digit in octet
for i,x in enumerate(reversed(a)):
    b[i//3]+=pow(2,i%3)*x               # 111
                                        # 421
print("".join(map(str,reversed(b))))