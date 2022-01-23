
def palin(left : int, right : int) -> str :
        while left >= 0 and right < len(words) and words[left] == words[right] : # while! 조건이 맞을 경우 계속 
                left -= 1 # 짝수는 2->4->6이렇게 증가 홀수는 1->3->5 이렇게 증가
                right += 1
        return words[left+1:right] # 문자열 슬라이스에서 뒤에 값-1 을 반환하므로 right은 -1 안하고 그냥

words = input()

if len(words) < 2 or words==words[::-1] :
        print(len(words))
        exit(0)

ans = ''
for i in range(len(words)-1) :
        ans = max(ans,palin(i,i+1),palin(i,i+2),key = len )

print(len(ans))
