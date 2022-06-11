def solution(n, computers):
    
    def dfs(i) : 
        vis[i] = 1 
        for a in range(n) : # 모든 컴퓨터를 확인 
            if computers[i][a] and vis[a] == 0 : # 연결되어있고 안가봤다면 
                dfs(a) # 가보자
    answer = 0
    vis = [0 for i in range(len(computers))]
    
    for i in range(n) : # 컴퓨터를 돌면서
        if vis[i] == 0 : # 안가봤으면 
            dfs(i) # 가본다 
            answer += 1  # 한 개의 네트워크
            
    return answer
