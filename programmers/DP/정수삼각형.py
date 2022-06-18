def solution(triangle):
    answer = 0
    
    for i in range(1,len(triangle)) :
        for idx in range(len(triangle[i])) :
            if idx == 0 : # 첫번째 원소
                triangle[i][0] += triangle[i-1][0] 
            elif idx == len(triangle[i])-1 : # last 원소 
                triangle[i][idx] += triangle[i-1][idx-1] 
            else : 
                triangle[i][idx] += max(triangle[i-1][idx-1],triangle[i-1][idx] )
    answer = max(triangle[-1])
        
    return answer
