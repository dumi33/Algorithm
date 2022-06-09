from collections import deque

def solution(priorities, location):
    answer = 0
    d = deque([(v,i) for i,v in enumerate(priorities)])
    
    
    while len(d) :
        tmp = d.popleft()
        if d and max(d)[0] > tmp[0] :
            d.append(tmp)
        else :
            answer+=1 
            if location == tmp[1] : 
                return answer
            
    
    return answer
