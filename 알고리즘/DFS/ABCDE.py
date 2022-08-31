def dfs(now, depth) :
    global finish 
    if depth == 4 : 
        finish = 1
        return 
    vis[now] = 1 
    for i in mp[now] :
        if vis[i] == 0 :
            dfs(i,depth+1)
            vis[i] = 0 

   
    
if __name__=="__main__" :
    n, m = map(int,input().split())
    mp = [[] for _ in range(n)]
    
    for i in range(m) :
        a,b = map(int,input().split())
        mp[a].append(b)
        mp[b].append(a)
    
    vis = [0]*(n+1)
    finish = 0
    
    for i in range(n) :
        dfs(i,0)
        vis[i] = 0 
        if finish : break
    if finish : print(1)
    else : print(0)
