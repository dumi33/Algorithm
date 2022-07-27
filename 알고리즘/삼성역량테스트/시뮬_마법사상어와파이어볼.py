dx = [-1,-1,0,1,1,1,0,-1]
dy = [0,1,1,1,0,-1,-1,-1]
            
     
            
if __name__=="__main__" :
    n,m,k = map(int,input().split())
    mp = [[[]for i in range(n+1)] for _ in range(n+1)]
    fire_ball = []
    for i in range(m) :
        r,c,m,s,d = map(int,input().split())
        fire_ball.append([r,c,m,s,d])
   
    for _ in range(k) : # k 초 이후에 
       
        # 방향 이동 
        for idx in range(len(fire_ball)) :
           r,c,m,s,d = fire_ball[idx] 
           nr,nc = (r + s*dx[d])%n, (c+ s*dy[d])%n 
           mp[nr][nc].append([m,s,d])
        
        fire_ball = []
        for i in range(n) :
            for j in range(n) :
                if len(mp[i][j])>=2 :
                    sum_m,sum_s,cnt_even,cnt_odd,cnt = 0,0,0,0,len(mp[i][j]) 
                    while mp[i][j] :
                        m,s,d = mp[i][j].pop(0)
                        sum_m += m
                        sum_s += s 
                        if d %2 == 0 :
                            cnt_even+=1 
                        else :
                            cnt_odd +=1 
                    if cnt == cnt_even or cnt == cnt_odd :
                        nd = [0,2,4,6]
                    else :
                        nd = [1,3,5,7]
                    if sum_m//5 :
                        for d in nd :
                            fire_ball.append([i,j,sum_m//5,sum_s//cnt,d])                            
                elif len(mp[i][j])==1 :
                    m,s,d=mp[i][j].pop(0)
                    fire_ball.append([i,j,m,s,d])
    ans = 0
    ans += sum([f[2] for f in fire_ball])
    print(ans)
