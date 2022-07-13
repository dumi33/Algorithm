def pos(now) :  # now는 확인할 배열 
    for j in range(1,n) :
        if abs(now[j] - now[j-1] ) > 1 : return False # 차이가 1이상 나면 False 
        
        if now[j] < now[j-1]  : # 현재 < 이전 , 오른쪽 스캔
            for k in range(l) :
                # 지도를 나가거나 이미 경사로를 세웠거나 길이가 다르거나 
                if j+k >=n or used[j+k] or now[j] != now[j+k] : return False
                used[j+k] = 1
                    
        elif now[j] > now[j-1] :
            for k in range(l) :
                if j-k -1 < 0 or used[j-k-1] or now[j-1] != now[j-k-1] : return False
                used[j-k-1] = 1 
    return True 

                        
if __name__=="__main__" :
    n,l = map(int,input().split())
    mp = [list(map(int,input().split())) for i in range(n)]
    ans = 0
    
    
    # 가로 확인 
    for i in range(n) :
        used = [0 for _ in range(n)]
        if pos(mp[i]) : # 길이 있는지 확인 
            ans+=1 

    # 세로 확인 
    for i in range(n) :
        used = [0 for _ in range(n)]
        if pos([mp[j][i] for j in range(n)]) : # 길이 있는지 확인 
            ans += 1
            
    print(ans )
