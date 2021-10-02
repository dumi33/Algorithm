#include<iostream>

using namespace std;

long long dp[1001];
int n, m, cnt;

int main() {
	dp[1] = 1;
	dp[2] = 3;
	cin >> n;
	for (int i = 3; i <= n; i++) {
		dp[i] =(dp[i - 1] + dp[i - 2]*2)%10007;
	}
	cout << dp[n];
	
}