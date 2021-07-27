#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dp[1001];
int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto& i : v) cin >> i;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int mx = 0;
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j]) { // 뒤가 더 크면
                mx = max(mx, dp[j]);
            }
        }
        dp[i] = mx + 1;
        ans = max(ans, dp[i]);
    }
   
    cout << ans;
}