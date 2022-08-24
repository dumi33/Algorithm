from collections import deque
import copy

def get(i,j) :
    if mp[i][j] : 
        q.append(mp[i][j])
        mp[i][j] = 0 
        
def merge(i,j,di,dj) :
	# 보드에 있는 칸들을 돌면서 
    while q :
        x = q.popleft()
        if not mp[i][j] :
            mp[i][j] = x 
        # 합쳐질수있다면
        elif mp[i][j] == x :
        	# 합친다
            mp[i][j] = x*2
            # 상하좌우에 맞춰서 di,dj를 더해준다.
            i,j = i+di,j+dj
        else :
        	# 다른 값이면 그냥 쌓인다.
            i,j = i + di,j+dj
            mp[i][j] = x 

def move(k) :
    # 상 
    if k == 0 :
        for j in range(n) :
            for i in range(n) :
                # q에 넣고 0으로 만든다. 
                get(i,j)
            # 0행 j열에서 부터 시작해서 몰아넣는다. 
            # 행이 1씩 증가하도록 한다. 
            merge(0,j,1,0) 
    # 하 
    elif k == 1 :
        for j in range(n) :
            for i in range(n-1,-1,-1) :
                get(i,j)
            # n-1행 j열에서부터 시작해서 몰아넣는다.
            # 행이 1씩 감소하도록 한다. 
            merge(n-1,j,-1,0)
    
    # 좌
    elif k ==2 :
        for i in range(n) :
            for j in range(n) :
                get(i,j)
            # i행 0열에서부터 시작해서 몰아넣는다.
            # 열이 1씩 증가하도록 한다. 
            merge(i,0,0,1)
    
    # 우
    else :
        for i in range(n) :
            for j in range(n-1,-1,-1) :
                get(i,j)
            # i행 n-1열 부터 시작해서 몰아넣는다.
            # 열이 1씩 감소하도록 한다. 
            merge(i,n-1,0,-1)


def solve(cnt) :
    global mp,ans
    if cnt == 5 :
        ans = max(ans,max(list(map(max,mp))))
        return 
    # 방향을 바꾸기전 mp을 저장 
    b = copy.deepcopy(mp)
    
    # 상하좌우 
    for k in range(4) :
        # mp를 변경 
        move(k)
        # 재귀, 한번 움직였으므로 cnt+1 
        solve(cnt+1)
        # 저장해두었던 방향을 바꾸기전 b를 다시 mp로 
        mp = copy.deepcopy(b)


if __name__=="__main__" :
    n = int(input())
    mp = [list(map(int,input().split()))for _ in range(n)]
    ans, q = 0, deque()

    solve(0)
    print(ans)
