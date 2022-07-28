dx = [0,-1,-1,-1,0,1,1,1]
dy = [-1,-1,0,1,1,1,0,-1]
            
     
            
if __name__=="__main__" :
    diagonal = [1,3,5,7]
    n,m = map(int,input().split())
    water = [list(map(int,input().split())) for i in range(n)]
    # 방향을 입력받음 
    ds = [list(map(int,input().split())) for i in range(m)]
    
    # 구름의 첫 위치 
    cloud = [[n-1,0],[n-1,1],[n-2,0],[n-2,1]]
    
    for d,s in ds :
        vis = [[0]*n for i in range(n)]
        
        next_cloud = []
        for idx in range(len(cloud)) :
            x,y = cloud[idx]
            # d방향으로 s칸 이동 
            nx,ny = (x+dx[d-1]*s)%n, (y+dy[d-1]*s)%n
            # 물의 양 1 증가 
            water[nx][ny] +=1 
            # 이동한 구름의 위치 저장 
            vis[nx][ny] = 1 
            next_cloud.append([nx,ny])
    
        for x,y in next_cloud :
            # 대각선 방향으로 
            cnt = 0 
            for i in diagonal :
                nx,ny = x + dx[i], y + dy[i]
                if 0<=nx<n and 0<=ny<n and water[nx][ny] :
                    cnt+=1 
            water[x][y] += cnt 
        
        cloud = []
        for i in range(n) :
            for j in range(n) :
                # 바구니에 저장된 물의 양이 2 이상이고 구름이 사리진 칸이 아니여야한다. 
                if water[i][j] >=2 and vis[i][j] == 0:
                    water[i][j] -=2 
                    # 새로운 구름의 위치 
                    cloud.append([i,j])
        
    print(sum(sum(water,[])))
        
