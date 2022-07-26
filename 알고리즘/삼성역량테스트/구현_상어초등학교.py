dx = [1,0,-1,0]
dy = [0,-1,0,1]
        
     
if __name__=="__main__" :
    n = int(input())
    dic = {} # 친한 친구 
    for i in range(n**2) :
        a,b,c,d,e = map(int,input().split())
        dic[a] = [b,c,d,e]
    
    mp = [[0]*n for i in range(n)]
    
    for k in dic.keys() :
        tmp = []
        for i in range(n) :
            for j in range(n) :
                empty,friend = 0,0
                if mp[i][j] == 0 : 
                    for dir in range(4) :
                        nx,ny = i + dx[dir], j + dy[dir]
                        if 0<=nx<n and 0<=ny<n : 
                            if mp[nx][ny] in dic[k] :
                                friend+=1 
                            elif mp[nx][ny] == 0 :
                                empty +=1 
                    tmp.append([friend,empty,i,j])
        tmp.sort(key = lambda x : (-x[0],-x[1],x[2],x[3]))
        x,y = tmp[0][2],tmp[0][3]
        mp[x][y] = k
    
    
    ans = 0
    for i in range(n) :
        for j in range(n):
            cnt = 0
            for dir in range(4) :
                nx,ny = i + dx[dir], j + dy[dir]
                if 0<=nx<n and 0<=ny<n :
                    if mp[nx][ny] in dic[mp[i][j]] :
                        cnt+=1 
            if cnt>0 :
                ans += 10**(cnt-1)
    print(ans) 
