#include<iostream>
#include<algorithm>
#include<queue>
#define x first
#define y second
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[1002][1002];
int dist[1002][1002];
int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    int n, m;
    cin >> m >> n;
    queue<pair<int, int> >Q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j]; // 익었는지 안익었는지 없는지 입력받기
            if (board[i][j] == 1) { // 익었다면 큐에 넣기
                Q.push({ i,j });
            }
            if (board[i][j] == 0) { //익지않았다면 
                dist[i][j] = -1; // -1넣기
            }
        }
    }
    while (!Q.empty()) { //비어있지 않을동안
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //범위를 벗어난다면 pass
            if (dist[nx][ny] >= 0) continue; //안익은것들만 -1이다. 즉 익었거나 없다면 pass
            dist[nx][ny] = dist[cur.x][cur.y] + 1;
            Q.push({ nx,ny });
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] == -1) {// 안익은게 존재한다면
                cout << -1;
                return 0; // 여기서 끝냄
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;
}

