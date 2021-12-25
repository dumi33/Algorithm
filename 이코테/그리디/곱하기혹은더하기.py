n = input()

sum = int(n[0])

for i in range(1, len(n)) :

    if sum <= 1 or int(n[i])<=1  : # 1이어도 덧셈이 유리!!
        sum += int(n[i])
    else : sum *= int(n[i])
         
print(sum)
