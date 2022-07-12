n,m = map(int,input().split())
mp =  [list(map(int,input().split())) for i in range (n)]

hs = []
ch = []
cb = [0]*m # 조합 # 선택할 치킨집의 인덱스를 담은 배열 (combination)
res = int(1e9)


def dfs(L,s) :
    global res
    if L==m: # 치킨집의 개수가 m 개 
        sum = 0 # 도시의 피자거리
        for j in range(len(hs)) : # 집들을 돌면서 
            x1 = hs[j][0]
            y1 = hs[j][1]
            dis = int(1e9)
            for x in cb : #   치킨집 좌표 
                x2 = ch[x][0]
                y2 = ch[x][1]
                dis = min(dis, abs(x2-x1)+abs(y1-y2))
            sum += dis 
        if sum <res : res = sum
        
    else :
        for i in range(s,len(ch)) :
            cb[L] = i
            dfs(L+1,i+1) 
            
for i in range(n) :
    for j in range(n) :
        if mp[i][j] == 1 : #  집 발견 
            hs.append((i,j))
        elif mp[i][j]==2 : # 치킨집 발결 
            ch.append((i,j))
dfs(0,0)
print(res)
