import copy
from collections import defaultdict 
           
# 상 하 좌 우     
dx = [-1,1,0,0]
dy = [0,0,-1,1]


cctv_dir = [
    [],
    [[0],[1],[2],[3]],
    [[0,1], [2,3]],
    [[0,3],[3,1],[1,2],[2,0]],
    [[0,2,3], [0,3,1],[1,2,3],[0,1,2]],
    [[0,1,2,3]]
]

def dfs(mp,depth) :
    global ans 
    if depth == len(cctv) :
        ans = min(ans,count_zero(mp)) 
        return 
    else :
        mp_copy = copy.deepcopy(mp)
        x,y,cctv_type = cctv[depth]
        for dir in cctv_dir[cctv_type] :
            watch(x,y,dir,mp_copy)
            dfs(mp_copy,depth+1)
            mp_copy = copy.deepcopy(mp)
        
        
def watch(x,y,dir,mp) :
    for d in dir :
        nx,ny = x,y
        while True :
            nx,ny = nx+dx[d], ny+dy[d]
            if 0<=nx<n and 0<=ny<m :
                if mp[nx][ny] ==6 : break
                elif mp[nx][ny] == 0 :
                    mp[nx][ny] = '#'
            else : break

def count_zero(mp) :
    cnt = 0
    for i in range(n) :
        for j in range(m) :
            if mp[i][j] == 0 :
                cnt+=1 
    return cnt    
        
                
    
if __name__=="__main__" :
    n,m = map(int,input().split())
    mp = [list(map(int,input().split())) for _ in range(n)]
    cctv = []    
    ans = int(1e9)

    for i in range(n) :
        for j in range(m) :
            if 1<=mp[i][j]<=5 :
                cctv.append([i,j,mp[i][j]])
    dfs(mp,0)
    print(ans)
