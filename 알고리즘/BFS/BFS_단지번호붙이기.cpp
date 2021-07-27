#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

#define X first
#define Y second

string board[26];
bool visit[26][26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> board[i];
	queue<pair<int, int>> Q;
	int num = 0;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == '0' || visit[i][j]) continue;
			num++;
			Q.push({ i, j });
			visit[i][j] = true;
			int size = 0;
			while (!Q.empty()) {
				size++;
				pair<int, int> cur = Q.front();
				Q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.X + dx[i];
					int ny = cur.Y + dy[i];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny] == '0' || visit[nx][ny]) continue;
					Q.push({ nx, ny });
					visit[nx][ny] = true;
				}

			}
			v.push_back(size);
		}

	}
	sort(v.begin(), v.end());
	cout << num << '\n';
	for (int i : v) cout << i << '\n';
}



