N,K = map(int,input().split())
items = []
dp = [0 for _ in range(K+1)]
for i in range(N):
    w,v = map(int,input().split())
    for j in range(K,w-1,-1):
        dp[j] = max(dp[j],dp[j-w]+v)
print(dp[-1])
