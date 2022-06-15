from collections import deque 
def solution(begin, target, words):
    answer = 0
    q = deque()
    q.append([begin,0]) # 0은 변화한 횟수
    vis = [0 for i in range(len(words))]
    
    while q :
        word , cnt = q.popleft()
        if word == target : 
            answer = cnt 
            break
        for i in range(len(words)) : # 단어들을 돌면서
            tmp_cnt = 0
            if vis[i] == 0 :  # 이 단어를 안썼다면
                for j in range(len(word)) :
                    if word[j] != words[i][j] :
                        tmp_cnt+=1 
                if tmp_cnt == 1 : # 만약 한글자만 다르다면
                    q.append([words[i],cnt+1])
                    vis[i] = 1  # 해당 단어 사용!
            
    
    return answer
