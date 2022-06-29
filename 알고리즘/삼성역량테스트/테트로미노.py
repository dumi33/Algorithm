n,m = map(int,input().split())
mp = [list(map(int,input().split())) for _ in range(n)]
vis = [[0]*m for i in range(n)]
dx = [-1,0,1,0]
dy = [0,1,0,-1]
ans = 0
max_val = max(map(max,mp))


def dfs(i,j,idx,total) :
    global ans
    if ans >= total + max_val * (3-idx) : # 더 커질수가 없음 
        return 
    if idx == 3 : # 4번 돌았다면 
        ans = max(ans,total)
        return 
    else :
        for k in range(4) : # 모든 방향으로 
            nx = i + dx[k]
            ny = j + dy[k]
            if 0<=nx<n and 0<=ny<m and vis[nx][ny]==0 :
                if idx == 1 : # 'ㅗ'모양을 위해  # ㅗ은 연달아 이을수 없다.
                    vis[nx][ny] = 1
                    dfs(i,j,idx+1, total + mp[nx][ny])
                    vis[nx][ny] = 0
                vis[nx][ny] = 1 
                dfs(nx,ny,idx+1, total+mp[nx][ny])
                vis[nx][ny] = 0
                    

for i in range(n) :
    for j in range(m) :
        vis[i][j] = 1 
        dfs(i,j,0,mp[i][j]) # [i,j]에서 시작, 초기값은 mp[i,j]
        vis[i][j] = 0
        
print(ans)
