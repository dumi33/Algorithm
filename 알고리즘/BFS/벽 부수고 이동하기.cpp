#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
const int dy[] = { 1,-1,0,0 };
const int dx[] = { 0,0,1,-1 };
queue<tuple<int, int, int> > q;
int mp[1001][1001];
int dp[1001][1001][2];
int n, m;
int bfs() {
    dp[0][0][1] = 1;
    q.push({ 0,0,1 });
    while (!q.empty()) {
        int y, x, b;
        tie(y, x, b) = q.front(); q.pop();
        if (y == n - 1 && x == m - 1) return dp[y][x][b];
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (!dp[ny][nx][b]) { // �Ȱ��� ��
                if (mp[ny][nx] == 0) { // �����ִ°�
                    dp[ny][nx][b] = dp[y][x][b] + 1;
                    q.push({ ny, nx, b });
                }
                else if (b) { // b�� 1�϶� // �̹� �ѹ��Ἥ 0���� �Ǹ� �ٽ� 1���� ���ٲ�
                    dp[ny][nx][0] = dp[y][x][b] + 1;
                    q.push({ ny, nx, 0 });
                }
            }
        }
    }
    return -1; // return ���� ���ٸ�..

}
int main() {
     cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        for (int j = 0; j < m; j++) {
            mp[i][j] = str[j] - '0';
        }
    }
    cout << bfs();
}