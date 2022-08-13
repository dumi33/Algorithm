from collections import deque


if __name__=="__main__" :
    n,m,t = map(int,input().split())
    mp = []
    for i in range(n) :
        mp.append(deque(list(map(int,input().split()))))
        
        
    for _ in range(t) :
        
        # 원판 돌리기 
        result = 0 
        x,d,k = map(int,input().split())
        for i in range(n) :
            result += sum(mp[i])
            if (i+1) % x == 0:
                if d == 0 :
                    mp[i].rotate(k)
                else :
                    mp[i].rotate(-k)
                    
                    
        if result > 0 :  
            # 모두 0이 아닐 때 
            delete = set()
            # 왼쪽 오른쪽 확인 
            for i in range(n) :
                for j in range(m-1) :
                    if mp[i][j]!=0 and mp[i][j] == mp[i][j+1] :
                        delete.add((i,j))
                        delete.add((i,j+1))
                if mp[i][0]!=0 and mp[i][0] == mp[i][m-1] :
                    delete.add((i,0))
                    delete.add((i,m-1))
                    
            # 위, 아래 확인 
            for j in range(m) :
                for i in range(n-1) :
                    if mp[i][j]!=0 and mp[i][j] == mp[i+1][j] :
                        delete.add((i,j))
                        delete.add((i+1,j))
            # 지울 값이 있을 때 
            if len(delete) > 0 :
                for x,y in delete :
                    mp[x][y] = 0
            # 지울 값이 없을 때 -> 평균을 구해 빼고 더해준다. 
            else :
                zero_cnt = 0
                max_v = 0
                for i in range(n) :
                    for j in range(m) :
                        if mp[i][j] == 0 :
                            zero_cnt +=1 
                        else :
                            max_v += mp[i][j]
                avg_v = max_v / ((m*n)-zero_cnt)
                for i in range(n) :
                    for j in range(m) :
                        if mp[i][j]!=0 and mp[i][j]> avg_v : mp[i][j] -=1 
                        elif mp[i][j]!=0 and mp[i][j] < avg_v : mp[i][j] +=1 
        # 전부 0일 경우 0을 출력한 후 끝내기 
        else :
            print(0)
            exit(0)
    # 모든 원판의 총합을 출력한다. 
    ans = 0
    for i in range(n) :
        ans += sum(mp[i])
    print(ans)
