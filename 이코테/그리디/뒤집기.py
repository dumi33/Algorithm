n = input()
# 구간의 개수를 count한다고 생각 
cntzero = 0 # 0의 구간
cntone = 0 # 1의 구간

if n[0] == '1' :
    cntone+=1
else : cntzero+=1

for i in range(1, len(n)) :  
    if  n[i] != n[i-1] : # 지금까지와 다른 수
        if n[i] == '1' : 
            cntone +=1
        else : cntzero += 1
    

print(min(cntzero, cntone))

    
