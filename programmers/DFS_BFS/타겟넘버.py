def solution(numbers, target):
    answer = 0
    n = len(numbers)
    def dfs(idx, result) : 
        if idx == n : #  주어진 수를 모두 사용
            if result == target : 
                nonlocal answer # 전역변수도 아닌데 지역변수 아님 
                answer +=1 
            return 
        else :
            dfs(idx+1, result+numbers[idx])
            dfs(idx+1, result-numbers[idx])
    dfs(0,0)
    
    return answer
