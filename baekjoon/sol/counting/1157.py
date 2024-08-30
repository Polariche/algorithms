def solution(word):
    keys = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" # allowed alphabets
    bin = {k:0 for k in keys}           # dict for counting
    word = word.upper()                 

    for w in word:
        bin[w]+=1                       # count per char
    
    res = "?"
    mx = 0
    
    for k,v in bin.items():             # find the char with max cnt
        if v>mx:
            mx=v
            res=k
        elif v==mx:
            res="?"

    return res

def main():
    word = input()
    print(solution(word))

main()