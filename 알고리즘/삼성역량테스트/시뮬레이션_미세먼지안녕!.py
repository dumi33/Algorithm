dx = [1,0,-1,0] 
dy = [0,-1,0,1]

            
if __name__=="__main__" :

    r,c,t = map(int,input().split())
    mp =[list(map(int,input().split())) for i in range(r)]
    
    for i in range(r) : # 공기청정기가 있는 행 알아내기 
        if mp[i][0] == -1 and mp[i+1][0] == -1 : 
            now = (i,i+1)
            break

    for _ in range(t) :
        
        # 확산 
        
        # 새롭게 확산된 값을 저장할 배열 
        new = [[0]*c for i in range(r)]
        
        for i in range(r) :
            for j in range(c) :
                if mp[i][j] >= 5 :   
                    each = mp[i][j] // 5 # 확산시킬 값 
                    cnt = 0 # 확산시킨 횟수 
                    for k in range(4) :
                        ndr,ndc  = i + dx[k], j +dy[k]
                        if 0<=ndr<r and 0<=ndc<c and mp[ndr][ndc]!= -1 :
                            new[ndr][ndc] += each
                            cnt+=1 
                    mp[i][j] = mp[i][j] - (each * cnt)
                    
        for i in range(r) :
            for j in range(c) :
                mp[i][j] += new[i][j]
                
            
        # 공기청정기 (순환)
        # 공기청정기의 위쪽 # 반시계 
        
        # 오른쪽으로 
        tmp = mp[now[0]][c-1] # 가장 오른쪽은 위로 올려야하므로 미리 빼준다
        for i in range(c-2,0,-1) : 
            mp[now[0]][i+1] = mp[now[0]][i]
        
        # 위로 
        tmp2 = mp[0][c-1]
        for i in range(now[0]-1) :
            mp[i][c-1] = mp[i+1][c-1]
        mp[now[0]-1][c-1] = tmp
        
        # 왼쪽으로 
        tmp = mp[0][0]
        for i in range(c-1) :
            mp[0][i] = mp[0][i+1]
        mp[0][c-2] = tmp2
        
        # 아래쪽으로 
        for i in range(now[0]-1, 1,-1) :
            mp[i][0] = mp[i-1][0]
        mp[now[0]][1] = 0
        mp[1][0] = tmp
        
        # 공기청정기의 아래쪽 
        
        # 오른쪽 
        tmp = mp[now[1]][c-1] # 가장 오른쪽은 위로 올려야하므로 미리 빼준다
        for i in range(c-2,0,-1) : 
            mp[now[1]][i+1] = mp[now[1]][i]
        
        # 아래로 
        tmp2 = mp[r-1][c-1]
        for i in range(r-1,now[1],-1) :
            mp[i][c-1] = mp[i-1][c-1]
        mp[now[1]+1][c-1] = tmp
        
        # 왼쪽으로 
        tmp = mp[r-1][0]
        for i in range(c-1) :
            mp[r-1][i] = mp[r-1][i+1]
        mp[r-1][c-2] = tmp2
        
        # 위로 
        for i in range(now[1]+1, r-1) :
            mp[i][0] = mp[i+1][0]
        mp[now[1]][1] = 0
        mp[r-2][0] = tmp
        
        
    ans= sum([sum(mp[i]) for i in range(r)])
    print(ans+2)
