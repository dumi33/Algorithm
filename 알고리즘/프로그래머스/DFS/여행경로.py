answer = []
def solution(tickets):   
    vis = [0]*len(tickets)
    
    def dfs(idx,val,tickets) :
        if idx == len(tickets) :
            answer.append(val[:])
            return
        else :
            for i in range(len(tickets)) :
                if tickets[i][0] == val[-1] and vis[i]==0 :
                    vis[i] = 1 
                    val.append(tickets[i][1])
                    dfs(idx+1, val,tickets)
                    vis[i] = 0
                    val.pop()
                    
    dfs(0,['ICN'],tickets)
    answer.sort() 
    return answer[0]
