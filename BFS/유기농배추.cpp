#include<iostream>
#include<queue>
#define x first
#define y second
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
using namespace std;
int main() {
    queue < pair<int, int> >Q;
    int t, mx = 0;
    cin >> t;
    for (int k = 0; k < t; k++) {
        int board[52][52] = {};
        int vis[52][52] = {}; //0으로 초기화
        int mx = 0;
        int n, m, l;
        cin >> n >> m >> l;
        for (int i = 0; i < l; i++) {
            int a, b;
            cin >> a >> b;
            board[a][b] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 1 || board[i][j] == 0) continue;
                Q.push({ i,j });
                mx++;
                vis[i][j] = 1;
                while (!Q.empty()) {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] == 1 || board[nx][ny] == 0) {
                            continue;
                        }
                        Q.push({ nx,ny });
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        cout << mx << "\n";
    }
}