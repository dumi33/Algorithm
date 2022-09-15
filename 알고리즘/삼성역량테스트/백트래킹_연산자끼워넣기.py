def dfs(idx, val) :
    if idx == len(num) :
        ans.append(val)
        return 
    else :
        for i in range(4) :
            if op[i] >= 1 :
                op[i] -=1 
                if i == 0 : dfs(idx+1, val+num[idx])
                elif i == 1 : dfs(idx+1, val-num[idx])
                elif i ==2 : dfs(idx+1, val*num[idx])
                else :
                    if val < 0 :
                        dfs (idx+1, -((-val) // num[idx]))
                    else : dfs(idx+1, val // num[idx])
                op[i] +=1 

if __name__=="__main__" :
    n = int(input())
    num = list(map(int,input().split()))
    op = list(map(int,input().split()))
    ans = []
    
    dfs(1,num[0]) 
    print(max(ans))
    print(min(ans))
