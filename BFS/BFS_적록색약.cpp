#include<iostream>
#include<queue>
#define x first
#define y second 
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
string board[101];
int vis[101][101];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    int cnt = 0;
    queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++) { //R의 경우
        for (int j = 0; j < n; j++) {
            if (board[i][j] != 'R' || vis[i][j] == 1) continue;
            cnt++;
            Q.push({ i,j });
            vis[i][j] = 1;
            while (!Q.empty()) {
                pair<int, int> cur = Q.front();
                Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (board[nx][ny] != 'R' || vis[nx][ny] == 1) continue;
                    Q.push({ nx,ny });
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);
    for (int i = 0; i < n; i++) { //G의 경우
        for (int j = 0; j < n; j++) {
            if (board[i][j] != 'G' || vis[i][j] == 1) continue;
            cnt++;
            Q.push({ i,j });
            vis[i][j] = 1;
            while (!Q.empty()) {
                pair<int, int> cur = Q.front();
                Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (board[nx][ny] != 'G' || vis[nx][ny] == 1) continue;
                    Q.push({ nx,ny });
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);
    for (int i = 0; i < n; i++) { //B의 경우
        for (int j = 0; j < n; j++) {
            if (board[i][j] != 'B' || vis[i][j] == 1) continue;
            cnt++;
            Q.push({ i,j });
            vis[i][j] = 1;
            while (!Q.empty()) {
                pair<int, int> cur = Q.front();
                Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (board[nx][ny] != 'B' || vis[nx][ny] == 1) continue;
                    Q.push({ nx,ny });
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    cout << cnt << " ";
    cnt = 0;
    for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] || board[i][j] == 'B') continue;
            cnt++;
            queue<pair<int, int>> Q;
            vis[i][j] = 1;
            Q.push({ i, j });
            while (!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (vis[nx][ny] || board[nx][ny] == 'B') continue;
                    Q.push({ nx, ny });
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] || board[i][j] != 'B') continue;
            cnt++;
            queue<pair<int, int>> Q;
            vis[i][j] = 1;
            Q.push({ i, j });
            while (!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (vis[nx][ny] || board[nx][ny] != 'B') continue;
                    Q.push({ nx, ny });
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    cout << cnt << '\n';
}