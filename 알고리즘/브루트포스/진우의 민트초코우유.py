def dfs(jwx,jwy,hp,milk) : # x,y 위치, 체력, 마신 우유의 개수 
    global ans 
    for x,y in milks : # 우유의 위치 
        if village[x][y] == 2: # 먹지 않은 우유라면 
            dist = abs(jwx-x) + abs(jwy-y)
            if dist <= hp : # 거리가 체력보다 작거나 같다면 
                village[x][y] = 0 # 먹는다. 
                dfs(x,y,hp+h-dist,milk+1) # 체력은 h만큼 올라가고 dist만큼 내려간다.그리고 우유를 마셨으므로 +1 
                village[x][y] = 2
            
    # 현재 위치와 집까지의 거리가 체력보다 작거나 같다면 돌아갈 수 있다. 
    if abs(jwx-hx) + abs(jwy-hy) <= hp :
        ans = max(ans,milk)
    
if __name__=="__main__" :
    n,m,h = map(int,input().split())
    village = [list(map(int,input().split())) for _ in range(n)]

    milks = [] # 우유의 위치를 저장할 리스트 
    
    for i in range(n) :
        for j in range(n) :
            if village[i][j] == 1 : # 진우의 집 
                hx,hy = i,j
            elif village[i][j] == 2 : # 민트초코우유 
                milks.append([i,j])
    
    # 진우가 마실수있는 민트초코우유의 최대 개수 
    ans = 0
    dfs(hx,hy,m,0) # 진우의 집, 초기체력 전달 
    print(ans)
