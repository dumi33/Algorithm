def solution(n, times):
    answer = 0
    left, right = 1, max(times) * n 
    # right은 가장 오래걸리는 심사관에게 모두 
    
    while left <= right :
        mid = (left + right) // 2
        people = 0 
        for time in times :
            people += mid // time
            if people >= n : # 이미 해야할 사람보다 더 많이 심사한다면 
                break
        if people >=n : # 심사한 사람이 많다 -> 시간을 줄인다. 
            answer = mid
            right = mid -1 
        else : # 심사한 사람이 더 적다 -> 시간을 늘린다. 
            left = mid +1 
            
    
    return answer
