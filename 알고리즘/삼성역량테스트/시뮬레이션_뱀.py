from collections import deque

# 하 우 상 좌 
dx = [1,0,-1,0]
dy = [0,1,0,-1]


def change(d,c) :
    if c == "L" : # 왼쪽으로 방향 틀기 
        d = (d+1) %4 
    else : # 오른쪽으로 방향 틀기 
        d = (d-1) %4 
    return d 

def start() :
    direction = 1 # 초기방향 # 우 
    time = 1
    x,y = 0,0
    vis = deque([[x,y]])
    mp[x][y] = 2 # 뱀이 지나갔던 곳 
    while True :
        x,y = x + dx[direction] , y + dy[direction]
        if 0<=x<n and 0<=y<n and mp[x][y] != 2 : # 갈 수있는 곳 
            if mp[x][y] == 0 :
                tmp_x,tmp_y = vis.popleft() 
                mp[tmp_x][tmp_y] = 0 # 꼬리 제거
            mp[x][y] = 2
            vis.append([x,y])
            if time in times.keys() :
                direction = change(direction,times[time])
            time+=1
        else :
            return time 
                        
if __name__=="__main__" :
    n = int(input())
    k = int(input())
    mp = [[0]*(n) for i in range(n)]
    for i in range(k) :
        x,y = map(int,input().split())
        mp[x-1][y-1] = 1
    L = int(input())
    times = {}
    for i in range(L) :
        x,c = input().split()
        times[int(x)]=c
    print(start()) 
