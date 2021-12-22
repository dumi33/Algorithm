n,m = map(int, input().split())

MAX = 0

for i in range(n):
    data = list(map(int, input().split()))    
    if MAX < min(data) :
        MAX = min(data)
    
print(MAX)
