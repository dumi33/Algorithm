if __name__=="__main__" :
    n = int(input())
    arr = list(map(int,input().split()))
    dy = [1]*n
    for i in range(1,n) :
        for j in range(i) :
            if arr[i] > arr[j] :
                dy[i] = max(dy[i],dy[j]+1)
    print(max(dy)) 
            
