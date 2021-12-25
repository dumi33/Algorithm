n = int(input())
data = list(map(int,input().split()))

data.sort()

cnt = 0 # 그룹의 개수 
tmp = 0 # 현재 그룹에 포함된 모험가의 수
for i in data : 
    tmp+=1
    if tmp >= i: # 큰 경우도 생각해야한다.  
        cnt+=1
        tmp = 0

print(cnt) 
