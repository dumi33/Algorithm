#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
string board[1002]; //미로를 저장
int dist1[1002][1002]; //불의 시간을 저장
int dist2[1002][1002]; //지훈이의 시간을 저장
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
#define x first
#define y second
int main() {
    queue<pair<int, int> >Q1;
    queue<pair<int, int> >Q2;
    int R, C;
    cin >> R >> C;
    for (int i = 0; i < R; i++) { //모든 거리를 -1로 초기화
        fill(dist1[i], dist1[i] + C, -1);
        fill(dist2[i], dist2[i] + C, -1);
    }
    for (int i = 0; i < R; i++) {
        cin >> board[i]; //미로를 입력받음
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 'F') {
                Q1.push({ i,j });
                dist1[i][j] = 0;// 그곳으로 시작지점
            }
            if (board[i][j] == 'J') {
                Q2.push({ i,j });
                dist2[i][j] = 0;
            }
        }
    }
    //  불의 BFS
    while (!Q1.empty()) { //뭔가 있으면 멈추지않음
        pair<int, int> cur = Q1.front();
        Q1.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || nx >= R || nx < 0 || ny >= C) continue; //범위 벗어나면 pass
            if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            //이미 와봤거나 #(벽)이면 pass
            dist1[nx][ny] = dist1[cur.x][cur.y] + 1;
            Q1.push({ nx,ny });
        }

    } // 지훈이의 BFS 
    while (!Q2.empty()) { //뭔가 있으면 멈추지않음
        pair<int, int> cur = Q2.front();
        Q2.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                cout << dist2[cur.x][cur.y] + 1; // 0부터 시작하였기에 +1을 해준다.
                return 0; // 탈출성공
            }
            if (dist2[nx][ny] >= 0 || board[nx][ny] == '#')continue;
            //이미 와봤거나 #(벽)이면 pass
            if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.x][cur.y] + 1) {
                continue;
            } // 불이 지훈이보다 빠르다면 pass
            dist2[nx][ny] = dist2[cur.x][cur.y] + 1;
            Q2.push({ nx,ny });
        }
    }
    cout << "IMPOSSIBLE";
}