#include<iostream>
#include<queue>
#define x first
#define y second
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int board[26][26];
int dis[26][26];
using namespace std;
int main() {
    queue<pair<int, int> > Q;

    int N, count;
    cin >> N; //N*N의 배열
    for (int i = 0; i < N; i++) {
        fill(dis[i], dis[i] + N, -1); //-1로 초기화
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j]; //입력받음
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int a;
            if (dis[i][j] != -1 || board[i][j] != 1) continue;
            Q.push({ i,j });
            while (!Q.empty()) {
                pair<int, int> cur = Q.front();
                Q.pop();
                count++;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];
                    if (dis[i][j] != -1 || board[i][j] != 1) continue;
                    a++;
                    Q.push({ i,j });
                    dis[i][j] = dis[cur.x][cur.y] + 1;
                }
            }
            cout << a << "\n";

        }
    }

}



