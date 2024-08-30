
def main():
    n,k = map(int, input().split(" "))
    nums = [i>=2 for i in range(n+1)]
    erased = 0
    p = n
    while erased < n-1:
        for num,kept in enumerate(nums):
            if kept:
                p = num
                break
        
        for q in range(p,n+1,p):
            if nums[q]:
                nums[q] = False
                erased+=1
                if erased ==k:
                    return q

print(main())