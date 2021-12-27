n = int(input())
m = int(input())
graph = [[]*n for i in range(n+1)] # 이차원 리스트 생성
for i in range(m):
    a,b = map(int,input().split()) 
    graph[a].append(b)
    graph[b].append(a)


cnt = 0
visited = [0]*(n+1) 

def dfs(start) :
    global cnt
    visited[start] = 1 # 해당 컴퓨터 감염 # 방문 체크
    for i in graph[start] :  # 방금 감염된 컴퓨터와 인점한 컴퓨터 확인
        if visited[i] == 0 :  # 인접한데 감염 안되었다면?
            dfs(i) # 감염시키기
            cnt+=1 # 개수 count 


dfs(1)   
print(cnt)
