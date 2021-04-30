#include<iostream>
#include<algorithm>
using namespace std;
int d[5002];

int dp(int n) {
    fill(d, d + n + 1, 999999);
    d[3] = 1;
    d[5] = 1;
    for (int i = 6; i <= n; i++) {
        d[i] = min(d[i - 3] + 1, d[i - 5] + 1);
    }
    return d[n];
}
int main() {
    int n;
    cin >> n;
    if (dp(n) >= 999999) cout << -1;
    else cout << dp(n);
}