dx = [1,0,-1,0] 
dy = [0,-1,0,1]

            
if __name__=="__main__" :
    mp = [[0]*101 for i in range(101)]
    for i in range(int(input())):
        x,y,d,g = map(int,input().split())
        dir = [d]
        for i in range(g) :
            tmp = []
            for j in range(len(dir)) :
                tmp.append((dir[-j-1]+1) %4)
            dir.extend(tmp)
        mp[x][y] = 1 
        for i in dir :
            x,y = x+dx[i],y+dy[i]
            mp[x][y] = 1
    ans = 0 
    for i in range(100) :
        for j in range(100) :
            if mp[i][j] == 1 :
                if mp[i+1][j] and mp[i+1][j+1] and mp[i][j+1] :
                    ans +=1 
    print(ans)
