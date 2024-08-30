def sol1(pattern,file):
    if pattern == file:
        # exact match
        return "DA"
    return "NE"

def sol2(pre,post,file):
    if len(file) < len(pre)+len(post):
        # prevent edge case : as*as / as
        return "NE"
    if file[:len(pre)] == pre and file[-len(post):] == post:
        # compare first / last
        return "DA"
    return "NE"

def main():
    N=int(input())
    pattern=input().split("*")
    if len(pattern)> 1:         # if *
        for i in range(N):
            print(sol2(*pattern,input()))
    else:                       # if not *
        for i in range(N):  
            print(sol1(pattern[0],input()))

    
main()