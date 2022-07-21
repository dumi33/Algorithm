def cal(x,y,d1,d2) :
    elec = [0 for i in range(5)] # 선거구 당 인구수 
    temp = [[0]*(n+1) for i in range(n+1)] # 선거구 
    
    # 경계선을 5번 선거구로 할당 
    for i in range(d1+1) :
        temp[x+i][y-i] = 5 # 1번 조건 
        temp[x+d2+i][y+d2-i] = 5 # 4번 조건 
    for i in range(d2+1) :
        temp[x+i][y+i] = 5 # 2번 조건 
        temp[x+d1+i][y-d1+i] # 3번 조건 
        
        
    # 경계선 내부를 5번으로 할당 
    for i in range(x+1, x+d1+d2) : # 행을 돌면서 
        flag = False 
        for j in range(1,n+1) : # 열을 돌면서 
            if temp[i][j] == 5 : # 경계선 발견! 
                flag = not flag 
            if flag :
                temp[i][j] = 5 
    
    # 전체 구역을 돌면서 1,2,3,4 부여 
    for r in range(1,n+1) :
        for c in range(1,n+1) :
            if r<x+d1 and c<=y and temp[r][c] == 0 :
                elec[0] += board[r][c] # 1번 
            elif r<=x+d2 and y<c and temp[r][c] == 0:
                elec[1] += board[r][c] #2번 
            elif x+d1<=r and c<y-d1+d2 and temp[r][c] == 0 :
                elec[2] += board[r][c] # 3번  
            elif x+d2< r and y-d1+d2<= c and temp[r][c] == 0:
                elec[3] += board[r][c] # 4번 
            elif temp[r][c] == 5:
                elec[4] += board[r][c] # 5번 
    return max(elec) - min(elec)
            
                
                
            
                    
if __name__=="__main__" :
    n = int(input())
    board = [[]]

    for _ in range(n):
        # 1-index로 맞추기위해서 
        board.append([0] + list(map(int, input().split())))

    
    answer = int(1e9)
    for x in range(1,n+1) :
        for y in range(1, n+1) :
            for d1 in range(1,n+1) :
                for d2 in range(1,n+1) :
                    if 1<=x<x +d1 +d2 <=n and 1<=y-d1<y<y+d2<=n :
                        answer = min(answer ,cal(x,y,d1,d2))
    print(answer)
