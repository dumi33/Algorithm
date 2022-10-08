from collections import deque 
import copy 

dx = [0,1,0,-1]
dy = [1,0,-1,0]


def bfs(q,vis,tmp) :
    isTrue = 1 
    while q : 
        x,y,cost = q.popleft()
            # 동, 서, 남, 북 다 가봐야죠 
        for dir in range(4) :
            nx,ny = x + dx[dir], y + dy[dir]
            # 대기실 안, 2번만에 이동, 방문한적 없는 
            if 0<=nx<5 and 0<=ny<5 and cost+1 <=2 and vis[nx][ny] == 0:
            	# 사람이 있다? 
                if tmp[nx][ny] == 'P' : 
                    isTrue=0
                # 빈자리면 덱에 넣어요 
                elif tmp[nx][ny] == 'O' :
                    q.append([nx,ny,cost+1])
                    vis[nx][ny] = 1
    return isTrue 

def solution(places):
    answer = []
    for room in places :
        tmp = []
        q = deque()
        vis = [[0]*5 for _ in range(5)]
        for i in room :
            tmp.append(list(i))
        ifroomTrue = 1
        for i in range(5) :
            for j in range(5) :
            	#  사람을 발견해서 q에 넣을 때마다 BFS를 돌린다. 
                if tmp[i][j] == 'P' :
                    q.append([i,j,0])
                    vis[i][j] = 1 
                    if bfs(q,copy.deepcopy(vis),tmp)==0 : ifroomTrue = 0 
                    vis[i][j]  = 0
        answer.append(1) if ifroomTrue else answer.append(0)          
                
    return answer
