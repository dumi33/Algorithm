from collections import deque


def indexing() :
    x,y = n//2, n//2
    dx = [0,1,0,-1]
    dy = [-1,0,1,0]
    depth = 0
    while True : 
        for dir in range(4) :
            if dir %2 ==0 :
                depth+=1 
            for _ in range(depth) :
                x,y = x+dx[dir],y + dy[dir]
                graphIdx.append([x,y])
                if x==0 and y ==0 : return 
    
    
def magic_shark(dir,dist) :
    x,y = n//2, n//2
    # 북 남 서 동 
    dx = [-1,1,0,0]
    dy = [0,0,-1,1]
    
    # dir 방향으로 dist만큼 
    for i in range(dist) :
        x += dx[dir]
        y += dy[dir]
        # 0으로 만들어줌 
        if 0<=x <n and 0<=y<n :
            mp[x][y] = 0
    # 0을 채워준다. 
    fill_blank()
    # 구슬 폭발 
    while bomb() :
        # 폭발한 친구가 있으면 빈칸 채우기 
        fill_blank()
    # 구슬 증식 
    grouping()
    
def fill_blank() :
    blankIdx  = deque()
    
    # 그래프를 돌면서 
    for x,y in graphIdx :
        # 비어있는 칸 발견 
        if mp[x][y] == 0 :
            blankIdx.append([x,y])
        # 비어있지 않고 비어있는 칸이 존재할 때 
        elif mp[x][y] >0 and blankIdx :
            # 비어있는 칸을 빼서 
            nx,ny = blankIdx.popleft()
            # 비어있는 칸에 넣어준다. 
            mp[nx][ny] = mp[x][y]
            mp[x][y] = 0 
            blankIdx.append([x,y])
def bomb() :
    vis = deque()
    cnt = 0 
    num = -1 
    flag = False 
    for x,y in graphIdx :
        # 연속된 구슬이라면 
        if num == mp[x][y] :
            vis.append([x,y])
            cnt +=1 
        # 연속된 구슬이 아니라면 
        else :
            # 4개 이상 연속 된 경우 
            if cnt >=4 :
                # 폭파된 구슬 개수 저장 
                score[num-1] += cnt 
                flag = True 
            # 폭파할 구슬들 
            while vis :
                nx,ny = vis.popleft()
                # 4개 이상이었다면 
                if cnt >= 4 :
                    mp[nx][ny] = 0
            num = mp[x][y] 
            cnt = 1 
            vis.append([x,y])
    return flag
            
def grouping() :
    cnt = 1 
    tmpx,tmpy = graphIdx[0]
    num = mp[tmpx][tmpy]
    nums = []
    for i in range(1,len(graphIdx)) :
        x,y = graphIdx[i][0],graphIdx[i][1]
        # 동일한 경우 
        if num == mp[x][y] :
            cnt +=1 
        # 동일하지 않으면 
        else :
            nums.append(cnt)
            nums.append(num)
            num = mp[x][y] 
            cnt = 1 
    idx = 0
    for x,y in graphIdx :
        if len(nums)==0 :
            break
        mp[x][y] = nums[idx]
        idx +=1 
        if idx==len(nums) : break
    
                
    
             
                

if __name__=="__main__" :
    n,m = map(int,input().split())
    mp = [list(map(int,input().split())) for i in range(n)]
    magic = []
    score = [0]*3
    
    for i in range(m) :
        magic.append(list(map(int,input().split())))
    
    # 그래프를 덱으로 일렬로 늘여뜨려 놓는다고 생각 
    graphIdx = deque()
    indexing()
    
    for d,s in magic :
        magic_shark(d-1,s)
    
    ans = 0
    for i in range(3) :
        ans += (i+1)*score[i]
    print(ans)
