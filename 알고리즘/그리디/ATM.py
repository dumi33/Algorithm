n = int(input())

data = list(map(int,input().split()))

data.sort()

all = 0
tmp = 0

for i in range(n):
    tmp += data[i]
    i+=1
    all += tmp

print(all)
