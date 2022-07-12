from collections import deque

dic = {}
for i in range(1,5) :
    dic[i] = deque(map(int,input()))

def rotate_left(x,dir) :
    if x <1 or dic[x][2] == dic[x+1][6] : return 
    
    if dic[x][2] != dic[x+1][6] :
        rotate_left(x-1,-dir)
        dic[x].rotate(dir)
    
def rotate_right(x,dir) :
    if x >4 or dic[x-1][2] == dic[x][6] : return 
    
    if dic[x-1][2] != dic[x][6] :
        rotate_right(x+1,-dir)
        dic[x].rotate(dir)

for i in range(int(input())) :
    x,dir = map(int,input().split())
    rotate_left(x-1,-dir)
    rotate_right(x+1,-dir)
    dic[x].rotate(dir)
    
ans = 0
for i in range(1,5) :
    if dic[i][0] == 1 : 
        ans += 2**(i-1)
print(ans)
