#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int w, h, cnt;
int map[51][51];
int visit[51][51];
#define x first;
#define y second;
queue<pair<int, int> > q;
int dx[] = { -1,-1,-1,0,1,1,1,0 };
int dy[] = { -1,0,1,1,1,0,-1,-1 };
void bfs() {
    while (!q.empty()) {
        pair<int, int> tmp = q.front();
        int X = tmp.x;
        int Y = tmp.y;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = dx[i] + X;
            int ny = dy[i] + Y;
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (visit[nx][ny] == 1 || map[nx][ny] == 0) continue;
            q.push({ nx,ny });
            visit[nx][ny] = 1;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (;;) {
        cin >> w >> h;
        if ((w <= 0) || (h <= 0)) return 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (visit[i][j] == 0 && map[i][j] == 1) {
                    q.push({ i,j });
                    cnt++;
                    visit[i][j] = 1;
                    bfs();
                }
            }
        }
        cout << cnt << "\n";
        cnt = 0;
        memset(visit, 0, sizeof(visit));
    }

}