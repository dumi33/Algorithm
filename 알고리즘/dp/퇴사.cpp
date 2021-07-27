#include<iostream>
#include<algorithm>
int t[1001];
int p[1001];
int dp[1001];
using namespace std;
int main() {
    int n, next;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> p[i];
    }
    for (int i = 0; i < n; i++) {
        if (i + t[i] <= n) { //일할수있는경우
            dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
        }
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }
    cout << dp[n];
}