def oper(a,l):
    for idx, row in enumerate(a) :
        tmp = []
        for n in set(row) :
            if n :
                tmp.append((n,row.count(n)))
        tmp = sorted(tmp, key = lambda x : (x[1],x[0]))
        tmplen = len(tmp)
        if tmplen > 50 : tmplen = 50
        l = max(l,tmplen *2) # 최대 길이 갱신 
        a[idx] = []
        for i in range(tmplen) :
            a[idx].append(tmp[i][0])
            a[idx].append(tmp[i][1])
            
    for idx,row in enumerate(a) :
        for _ in range(l-len(row)) :
            a[idx].append(0)
    
    return a,l
        
if __name__=="__main__" :
    r,c,k = map(int,input().split())
    mp = [list(map(int,input().split())) for _ in range(3)]
    
    rlen,clen = 3,3
    for time in range(101) :
        if r<=rlen and c<=clen and mp[r-1][c-1] == k :
            print(time)
            exit(0)
        if rlen >= clen : # R연산 
            mp,clen = oper(mp,clen)
        else : # C연산
            mp,rlen = oper(list(zip(*mp)), rlen)
            mp = list(zip(*mp))
    print(-1)
