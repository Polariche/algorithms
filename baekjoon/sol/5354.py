import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    a = int(input())

    
    if a>2:
        print("#"*a)
        print("\n".join(["#"+"J"*(a-2)+"#"]*(a-2)))
        print("#"*a)
    elif a==2:
        print("##")
        print("##")
    else:
        print("#")
    
    print()