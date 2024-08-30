st=input()+" "
st=list(st)
n=len(st)
is_tag=False
ptr=n         # range 
# char category: '<', ' ', '>', etc
for i,c in enumerate(st):
    if not is_tag:
        if c=='<':
            is_tag=True                 # enter tag state
        if c==' ' or c=='<':
            if ptr<n:
                for j,t in enumerate(reversed(st[ptr:i])):
                    st[ptr+j]=t         # reverse the letter
            ptr=n                       # reset range
        else:
            ptr=min(ptr,i)              # record the first letter of regular word
    else:
        if c=='>':
            is_tag=False                # exit tag state
    
print(''.join(st))