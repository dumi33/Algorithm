#include<iostream>
#include<queue>
#include<algorithm>
int dx[8] = { 2,1,-1,-2,-2,-1,1,2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dis[302][302];
#define x first
#define y second
using namespace std;
int main() {

    int t, l;
    cin >> t;

    while (t--) {
        queue<pair<int, int> >Q;
        cin >> l;
        for (int j = 0; j < l; j++) {
            fill(dis[j], dis[j] + l, -1);
        }
        int x1, y1, x2, y2;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        dis[x1][y1] = 0;
        Q.push({ x1,y1 });

        while (!Q.empty()) {
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int dir = 0; dir < 8; dir++) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if (dis[nx][ny] != -1) continue;
                dis[nx][ny] = dis[cur.x][cur.y] + 1;
                Q.push({ nx,ny });
            }
        }
        cout << dis[x2][y2] << "\n";
    }
}