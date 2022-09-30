# 0은 1으로 , 1은 0으로 
def change(num) :
    return 1 - num


def flip(state,cnt) :
	# 첫번째 전구를 킨다. 
    if cnt == 1 :
        state[0] = change(state[0])
        state[1] = change(state[1])
    for j in range(1,n) :
        if state[j-1] != goal[j-1] :
            cnt+=1 
            state[j-1] = change(state[j-1])
            state[j] = change(state[j])
            # 마지막 원소가 아니라면 
            # 3개를 변경 
            if j != n-1 : 
                state[j+1] = change(state[j+1])
    if state == goal : return cnt 
    else : return -1 
        
if __name__=="__main__" :
    n = int(input())
    origin = list(map(int,list(input())))
    goal = list(map(int,list(input())))

	# 첫번째 전구를 안바꾼다. 
    ans1 = flip(origin[:],0)
    # 첫번째 전구를 바꾼다.
    ans2 = flip(origin[:],1)
    
    # 바꿀수있는 방법이 없는경우
    if ans1 == -1 and ans2 == -1 : print(-1)
    # -1일경우에는 그 값이 min이 되어버려서 둘 다 양수라면 min을 , 
    # 아니라면 max를 출력 
    else :
        print(min(ans1,ans2)if (ans1>=0 and ans2>=0) else max(ans1,ans2))
