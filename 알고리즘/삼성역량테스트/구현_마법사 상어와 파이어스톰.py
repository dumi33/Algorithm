from collections import deque
from itertools import combinations as c 


dx = [1,0,-1,0]
dy = [0,1,0,-1]

def rotate_and_melt(mp, len_board, L) :
    
    # 회전한 board 저장용 
    new_mp = [[0]*(len_board) for i in  range(len_board)]
    
    
    # rotate 
    r_size = 2**L 
    for x in range(0,len_board,r_size) :
        for y in range(0,len_board, r_size) :
            for i in range(r_size):
                for j in range(r_size) :
                    new_mp[x+j][y+r_size-i-1] = mp[x+i][y+j]
    mp = new_mp
    melting_list= []
    for x in range(len_board) :
        for y in range(len_board) :
            ice_count = 0
            for dir in range(4) :
                nx,ny  = x + dx[dir], y + dy[dir]
                if 0<=nx<len_board and 0<=ny<len_board and mp[nx][ny] > 0:
                    ice_count+=1 
            if ice_count < 3 and mp[x][y] >0 :
                melting_list.append([x,y])


    # 저장된 얼음들 녹이기 
    for x,y in melting_list :
        mp[x][y] -=1 
    
    return mp 


def check_ice_bfs(mp,len_board) :
    vis = [[0]*(len_board) for i in range(len_board)]
    max_area_cnt = 0
    for x in range(len_board) :
        for y in range(len_board) :
            area_cnt = 0
            if vis[x][y] or mp[x][y] == 0 :
                continue 
            q = deque()
            q.append([x,y])
            vis[x][y] = 1 
            
            while q :
                cx,cy = q.popleft()
                area_cnt+=1 
                
                for i in range(4) :
                    nx,ny= cx + dx[i], cy+ dy[i]
                    if 0<=nx<len_board and 0<=ny<len_board and mp[nx][ny] >0 and vis[nx][ny]==0 :
                        vis[nx][ny] =1 
                        q.append([nx,ny])
            max_area_cnt  = max(max_area_cnt, area_cnt)
            
            
    # 남아있는 얼음의 합 
    print(sum(sum(mp,[])))
    print(max_area_cnt)
            
    
    
    
if __name__=="__main__" :
    n,q = map(int,input().split())
    len_board = 2**n 
    mp = [list(map(int,input().split())) for i in range(len_board)]
    L_list = list(map(int,input().split()))
    
    for L in L_list :
        mp = rotate_and_melt(mp,len_board,L)
    
    check_ice_bfs(mp,len_board)
