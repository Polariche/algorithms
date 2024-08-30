st = input()
is_c = True
is_j = True
next_change = False     # records the existence of _

def big(s):
    # big chars < small chars, ord('a') = 97
    return ord(s) < 97

if st[0] == "_" or st[-1] == "_" or big(st[0]):
    print("Error!")
    st=""    
    
ns = ""

for i,s in enumerate(st):
    
    if s=="_" and not next_change:
        # c -> java, current letter is _
        is_j=False
        next_change=True

    elif big(s) and i>0:
        # java -> c
        is_c=False
        ns+="_"+s.lower()
    
    else:
        if is_c and next_change:
            # c -> java, previous letter was _
            ns+=s.upper()
            next_change=False
        else:
            # java -> c, ordinary
            ns+=s.lower()

if not is_c and not is_j:
    # _ and big letters are both present
    print("Error!")
else:
    print(ns)