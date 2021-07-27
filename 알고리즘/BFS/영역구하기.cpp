#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<int> v;
#define x first
#define y second
int board[101][101];
void fill(int a, int b, int c, int d) { // 주어진 영역을 1로 만든다.
    for (int i = a; i < c; i++) {
        for (int j = b; j < d; j++) {
            board[i][j] = 1;
        }
    }
}
int main() {

    int n, m, k;
    cin >> m >> n >> k;
    int a, b, c, d;
    for (int i = 0; i < k; i++) {
        cin >> a >> b >> c >> d;
        fill(a, b, c, d); // 1로 변환
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) { // 영역이 아닌곳 발견!
                queue<pair<int, int> >Q;
                Q.push({ i,j }); // 큐에 넣는다.
                board[i][j] = 1; // 들렀음
                int cnt = 0;
                while (!Q.empty()) { // 큐가 빌때까지 (즉, 주변에 0이 있는곳이 없을때까지)
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    cnt++; // 0의 개수
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //영역을 나가버림
                        if (board[nx][ny] == 0) { // 0인곳 발견
                            board[nx][ny] = 1;
                            Q.push({ nx,ny });
                        }
                    }
                } // 그 근방 0 탐색 완료
                v.push_back(cnt); // 개수를 넣는다.
            }
        }
    }
    cout << v.size() << "\n";
    sort(v.begin(), v.end()); // 오름차순 정렬
    for (int t : v) cout << t<<" "; 
}