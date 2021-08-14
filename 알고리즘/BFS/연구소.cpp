#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int dy[4] = { 0,0,1,-1 };
const int dx[4] = { 1,-1,0,0 };
int n, m, map[9][9];
int virus_map[9][9];
typedef pair<int, int> P;
int bfs() {
    queue<P> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            virus_map[i][j] = map[i][j]; // 옮기기
            if (virus_map[i][j] == 2) { // 바이러스 있는 곳을 큐에 저장
                q.push({ i,j });
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (virus_map[nx][ny] == 0) { //이동가능 지점
                virus_map[nx][ny] = 2; //바이러스 전파
                q.push({ nx,ny });
            }
        }
    }
    int safe = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (virus_map[i][j] == 0) { // 안전구역에는
                safe++;
            }

        }
    }
    return safe;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    int mx_safe = 0; // 안전영역의 크기
    for (int a1 = 0; a1 < n; a1++) { // 1번벽
        for (int a2 = 0; a2 < m; a2++) {
            if (map[a1][a2] != 0) continue; //0이 아니라면 벽을 세울수없으므로
            for (int b1 = 0; b1 < n; b1++) { //2번벽
                for (int b2 = 0; b2 < m; b2++) {
                    if (map[b1][b2] != 0) continue; //0이 아니라면 벽을 세울수없으므로
                    for (int c1 = 0; c1 < n; c1++) { //3번벽
                        for (int c2 = 0; c2 < m; c2++) {
                            if (map[c1][c2] != 0) continue; //0이 아니라면 벽을 세울수없으므로
                            if (a1 == b1 && a2 == b2) continue; // 같은 자리에 벽을 세울수없으므로
                            if (a1 == c1 && a2 == c2) continue;
                            if (c1 == b1 && c2 == b2) continue;
                            //벽을 세워요
                            map[a1][a2] = 1;
                            map[b1][b2] = 1;
                            map[c1][c2] = 1;

                            int numofsafe = bfs();
                            mx_safe = max(numofsafe, mx_safe);

                            //벽을 없애요
                            map[a1][a2] = 0;
                            map[b1][b2] = 0;
                            map[c1][c2] = 0;
                        }
                    }
                }
            }
        }
    }
    cout << mx_safe;

}