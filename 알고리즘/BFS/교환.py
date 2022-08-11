from collections import deque
         
def bfs(n,K) :
    # 방문 확인 
    vis = set()
    # n을 0번 변화로 만들 수 있다. 
    vis.add((n,0))
    d = deque()
    d.append([n,0])
    ans = 0
    while d :
        num,k = d.popleft()
        if k == K :
            ans = max(ans,num)
            continue 
        num = list(str(num))
        # i 와 m 사이에는 j가 있어야하므로 m-1까지 
        for i in range(m-1) : 
            for j in range(i+1,m) :
                # 첫번째 자리에 0이 옮겨진다면
                if i == 0 and num[j] == '0' :
                    continue
                num[i],num[j] = num[j],num[i]
                # i와 j의 순서를 바꾼 문자열을 합친후 숫자로 만듦
                nn = int(''.join(num))
                if (nn,k+1) not in vis :
                    d.append([nn,k+1])
                    vis.add((nn,k+1))
                num[i],num[j] = num[j],num[i]
    return ans if ans else -1 
                
                

if __name__=="__main__" :
    n,K = map(int,input().split())
    m = len(str(n))
    print(bfs(n,K))
