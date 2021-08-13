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
            if (!dp[ny][nx][b]) { // 안가본 곳
                if (mp[ny][nx] == 0) { // 갈수있는곳
                    dp[ny][nx][b] = dp[y][x][b] + 1;
                    q.push({ ny, nx, b });
                }
                else if (b) { // b가 1일때 // 이미 한번써서 0으로 되면 다시 1으로 못바꿈
                    dp[ny][nx][0] = dp[y][x][b] + 1;
                    q.push({ ny, nx, 0 });
                }
            }
        }
    }
    return -1; // return 값이 없다면..

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