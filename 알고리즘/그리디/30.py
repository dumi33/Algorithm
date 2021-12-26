arr = input()
arr = sorted(arr, reverse = True)
sum = 0
# 30의 배수는 0으로 끝나고 각 자리수의 합이 3의 배수
if '0' not in arr :
    print(-1)

else : 
    for i in arr :
        sum += int(i) 
    if sum %3 == 0 : # 3으로 나눠지면
        print(''.join(arr))
    else : print(-1)
