# 동 서 북 남      
dx = [0,0,-1,1]
dy = [1,-1,0,0]

def dfs(i,j,cnt,sum) :
    global ans 
    # 시간낭비를 줄이기 위해서 
    if ans >= sum + max_v*(3-cnt) : return 
    if cnt == 3 :
        ans = max(ans,sum)
        return 
    else :
        for dir in range(4) :
            nx,ny = i + dx[dir], j + dy[dir]
            if 0<=nx<n and 0<=ny<m and check[nx][ny] ==0 :
                # 'ㅗ'모양을 위해서 
                if cnt ==1 :
                    check[nx][ny] = 1 
                    dfs(i,j,cnt+1, sum+mp[nx][ny])
                    check[nx][ny] = 0 
                check[nx][ny] = 1 
                dfs(nx,ny,cnt+1,sum+mp[nx][ny])
                check[nx][ny] = 0


if __name__=="__main__" :
    n,m = map(int,input().split())
    mp = [list(map(int,input().split())) for _ in range(n)]
    check = [[0]*m for _ in range(n)]
    ans = 0
    max_v = max(map(max,mp))
    
    for i in range(n) :
        for j in range(m) :
            check[i][j] = 1 
            dfs(i,j,0,mp[i][j])
            check[i][j] = 0

    print(ans)
