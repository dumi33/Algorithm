from collections import deque
import copy

           
# 동 서 북 남      
dx = [0,0,-1,1]
dy = [1,-1,0,0]


def bfs() :
    global ans 
    tmp_mp = copy.deepcopy(mp)    
    for i in range(n) :
        for j in range(m) :
            if tmp_mp[i][j]==2 :
                q.append([i,j])
    while q :
        x,y = q.popleft()
        for dir in range(4) :
            nx,ny = x + dx[dir], y + dy[dir]
            if 0<=nx<n and 0<=ny<m and tmp_mp[nx][ny] == 0 :
                tmp_mp[nx][ny] = 2 
                q.append([nx,ny]
    cnt = 0
    for i in tmp_mp :
        cnt += i.count(0)
    ans = max(ans,cnt)
                         

def wall(x) :
    if x == 3 :
        bfs()
        return 
    for i in range(n) :
        for j in  range(m) :
            if mp[i][j] == 0:
                mp[i][j] = 1
                wall(x+1)
                mp[i][j] = 0 


if __name__=="__main__" :
    n,m = map(int,input().split())
    mp = [list(map(int,input().split())) for _ in range(n)]
    ans = 0
    q = deque()

    wall(0)
    print(ans)
