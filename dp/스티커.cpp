#include <iostream>
#include <algorithm>
using namespace std;
int dp[100000][2]; // dp[i][0] : 0~i-1�� ��ü + i�� 0�࿡ ���� �ִ�, dp[i][1] : 0~i-1�� ��ü + i�� 1�࿡ ���� �ִ�
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
			dp[i][0] = max(st[i][0] + dp[i - 1][1], dp[i - 1][0]);//{i���� 0���� �� + ������(i-1)��  1���� ��} �� �������� 0���� �� �� ū��
			dp[i][1] = max(st[i][1] + dp[i - 1][0], dp[i - 1][1]);//{i���� 1���� �� + ������(i-1)��  0���� ��} �� �������� 1���� �� �� ū��
		}
		cout << max(dp[N - 1][0], dp[N - 1][1]) << "\n"; //1��� 0���� �� �� ū��
	}
}