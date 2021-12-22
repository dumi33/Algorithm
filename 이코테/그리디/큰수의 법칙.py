n,m,k = map(int, input().split())
data = list(map(int, input().split()))

data.sort()
first = data[n-1] # 가장 큰수
second = data[n-2] # 두번째로 큰수

result = 0

while True:
    for i in range(k): #k 만큼
        if m == 0: # 총 덧셈 횟수 소진
            break
        result += first
        m-=1
    if m == 0 : 
        break
    result += second
    m-=1

print(result)


