if __name__=="__main__" :
    n = int(input())
    arr = list(map(int,input().split()))
    
    #  적어도 길이가 1
    dy = [1]*n
    
    for i in range(1,n) :
        # 앞의 원소들을 보며 
        for j in range(i) :
            # 작다면 
            if arr[i] > arr[j] :
                # 갱신
                dy[i] = max(dy[i],dy[j]+1)
    print(max(dy)) 
            
