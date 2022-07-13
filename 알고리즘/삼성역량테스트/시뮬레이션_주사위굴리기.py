dx = [0,0,-1,1] 
dy = [1,-1,0,0]

                        
if __name__=="__main__" :
    n,m,x,y,k = map(int,input().split())
    mp = [list(map(int,input().split())) for i in range(n)]
    order = list(map(int,input().split()))
    dice = [0 for i in range(6)]
    for i in range(k) :
        dir = order[i] - 1 
        nx,ny = x + dx[dir], y + dy[dir]
        if 0<=nx<n and 0<=ny<m : 
            if dir == 0 :
                dice[0],dice[2],dice[3],dice[5] =  dice[3],dice[0],dice[5],dice[2]
            elif dir == 1 :
                dice[0],dice[2],dice[3],dice[5] =  dice[2],dice[5],dice[0],dice[3]
            elif dir == 2 :
                dice[0],dice[1],dice[4],dice[5] =  dice[4],dice[0],dice[5],dice[1]
            else :
                dice[0],dice[1],dice[4],dice[5] =  dice[1],dice[5],dice[0],dice[4]
            if mp[nx][ny] == 0 :
                mp[nx][ny] = dice[5]
            else :
                dice[5] = mp[nx][ny]
                mp[nx][ny] = 0
            x,y = nx,ny 
            print(dice[0])
