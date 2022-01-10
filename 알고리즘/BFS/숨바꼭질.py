from collections import deque
x , y= map(int,input().split())

dist = [-1]*100001
def bfs(n):
    queue = deque()
    queue.append(n)
    while queue:
        node = queue.popleft()
        for i in (node+1, node-1,node*2) :
            if i < 0 or i > 100000 : continue
            if dist[i] == -1 : # 처음 방문
                dist[i] = dist[node]+1
                queue.append(i) 
dist[x] = 0
bfs(x)
print(dist[y])
