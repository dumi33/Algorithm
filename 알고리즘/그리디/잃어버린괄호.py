arr = input().split('-') # '-'로 나누기 
sum = 0

for i in arr[0].split('+') : 
    sum += int(i)
for i in arr[1:] : # 첫번째 이후 => - 기호 이후
        for j in i.split('+') : 
            sum-=int(j)

print(sum)
