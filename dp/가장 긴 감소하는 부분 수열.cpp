#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int dp[1001];
int main() {
    cin >> n;
    vector<int> v(n);
    for (int& i : v) cin >> i;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        dp[i] = 1; //기본길이 = 1
        for (int j = 0; j < i; j++) {
            if (v[i] < v[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
}