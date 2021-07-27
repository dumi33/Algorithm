#include <iostream>
#include <algorithm>
using namespace std;
int dp[100000][2]; // dp[i][0] : 0~i-1열 전체 + i열 0행에 대해 최댓값, dp[i][1] : 0~i-1열 전체 + i열 1행에 대해 최댓값
int st[100000][2];
int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> st[i][0];
		for (int i = 0; i < N; i++)
			cin >> st[i][1];
		dp[0][0] = st[0][0];
		dp[0][1] = st[0][1];
		for (int i = 1; i < N; i++) {
			dp[i][0] = max(st[i][0] + dp[i - 1][1], dp[i - 1][0]);//{i열의 0행의 값 + 이전열(i-1)의  1행의 값} 과 이전열의 0행의 값 중 큰것
			dp[i][1] = max(st[i][1] + dp[i - 1][0], dp[i - 1][1]);//{i열의 1행의 값 + 이전열(i-1)의  0행의 값} 과 이전열의 1행의 값 중 큰것
		}
		cout << max(dp[N - 1][0], dp[N - 1][1]) << "\n"; //1행과 0행의 값 중 큰것
	}
}