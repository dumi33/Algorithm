from collections import deque
n = int(input())
p,c = map(int, input().split())
m = int(input())
arr = [[] for _ in range(n+1)]


dist = [0]*(n+1)

def bfs(n) :
    queue = deque()
    queue.append(n)
    while queue :
        node = queue.popleft()
        for i in arr[node] : 
            if dist[i] ==0 :
                dist[i] = dist[node]+1
                queue.append(i)
            else : continue

for i in range(m) :
    x,y = map(int ,input().split())
    arr[x].append(y)
    arr[y].append(x)

bfs(p)
print(dist[c] if dist[c] > 0 else -1)
