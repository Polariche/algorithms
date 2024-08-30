import sys 
inputs = sys.stdin.readlines()

i = 0



while i<len(inputs):
    n,k = map(int, inputs[i].split(" "))
    i+=1
    x = list(map(int, inputs[i].split(" ")))
    i+=1

    multtree = 2**()

    for _ in range(k):
        cmd,a,b = inputs[i].split(" ")
        if cmd == "C":
            #x[a] = b
            pass
        elif cmd == "P":
            pass
        i+=1