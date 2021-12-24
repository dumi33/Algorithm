n = int(input())

n = 1000-n
data = [500,100,50,10,5,1]

cnt = 0

for i in data :
    cnt+= n // i # 몫
    n %= i # 나머지


print(cnt)
       
