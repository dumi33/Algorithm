n,m =map(int,input().split())
mp = [list(map(int,input().split())) for i in range(n)]
vis = [[0]*m for i in range(n)]
ans = 0 # 최대 안전영역 
dx = [-1,0,1,0]
dy = [0,1,0,-1]
tmp = [[0]*m for i in range(n)]


def virus(x,y) : # (x,y)로부터 바이러스를 퍼트린다. 
    for i in range(4) :
        nx = dx[i] + x
        ny = dy[i] + y
        if 0<=nx<n and 0<=ny<m and tmp[nx][ny] == 0 :
            tmp[nx][ny] = 2
            virus(nx,ny)

def Score() : # 안전영역의 개수를 구한다. 
    score = 0
    for i in range(n) :
        for j in range(m) :
            if tmp[i][j] == 0:
                score +=1
    return score

def dfs(count) :
    global ans
    if count == 3 : # 벽의 개수가 3개라면 
        for i in range(n) :
            for j in range(m) :
                tmp[i][j] = mp[i][j] # tmp로 복사
        for i in range(n) :
            for j in range(m) :
                if tmp[i][j] == 2 : # 바이러스가 있다면
                    virus(i,j) # 퍼트려
        ans = max(ans,Score()) #점수를 갱신 
        return
    for i in range(n) : 
        for j in range(m) :
            if count< 3 and mp[i][j] == 0 :
                mp[i][j] = 1 # 벽을 세워
                count+=1 
                dfs(count)
                mp[i][j] = 0
                count-=1 
dfs(0)
print(ans)
