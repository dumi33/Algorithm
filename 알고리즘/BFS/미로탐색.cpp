#include<iostream>
#include<queue>
#include<string>
using namespace std;
#define x first
#define y second
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
string board[102]; //0과 1을 저장
int dist[102][102]; //거리저장
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = -1; //거리를 -1로 모두 초기화
        }
    }
    queue<pair<int, int> > Q; //2개의 int로 queue를 만든다.
    Q.push({ 0,0 }); //좌측 상단
    dist[0][0] = 0; //가장 처음은 0으로 한다.
    while (!Q.empty()) { //비어있지않을동안 -> (뭔가가 있을동안)
        pair<int, int> cur = Q.front();//2개의 int pair형 변수(?) cur을 만들어 front를 저장한다.
        Q.pop();
        for (int dis = 0; dis < 4; dis++) {
            int nx = cur.x + dx[dis];
            int ny = cur.y + dy[dis];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 0보다 작거나 n,m 보다 클때는 for문의 다음으로 넘어간다.
            if (dist[nx][ny] >= 0 || board[nx][ny] != '1')continue; // 이미 왔던곳이거나 1이 아닐경우 pass
            dist[nx][ny] = dist[cur.x][cur.y] + 1;
            Q.push({ nx,ny });
        }

    }
    cout << dist[n - 1][m - 1] + 1;
}

