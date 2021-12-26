n = input()
arr = list(map(int, input().split()))

target = 1
arr.sort()
for i in arr :
    if target < i : 
        break
    else : target += i


print(target)
