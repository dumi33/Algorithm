#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int dx[] = { 0,-1,1,0 };
int dy[] = { 1,0,0,-1 };
#define x first
#define y second
int mp[101][101];
int check[101][101];
int mx, mn;
int ans = 0;
priority_queue < int > pq;
int n;

int bfs() {
    int cnt = 0;
    queue<pair<int, int> > q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!check[i][j]) {
                cnt++;
                check[i][j] = 1;
                q.push({ i,j });
                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = dx[dir] + cur.x;
                        int ny = dy[dir] + cur.y;
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (check[nx][ny] == 1) continue;
                        check[nx][ny] = 1;
                        q.push({ nx,ny });
                    }
                }
                
            }
        }
    }
    return cnt;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mp[i][j];
            mx = max(mx, mp[i][j]);
            mn = max(mn, mp[i][j]);
        }
    }
    if (mx == 1) cout << 1;
    else {
        for (int k = 1; k <= mx; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mp[i][j] <= k) check[i][j] = 1;

                }
            }
            ans = max(ans, bfs());
            memset(check, 0, sizeof(check));
        }

        cout << ans;
    }
    
    
}