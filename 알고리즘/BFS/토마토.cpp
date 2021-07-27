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
            cin >> board[i][j]; // �;����� ���;����� ������ �Է¹ޱ�
            if (board[i][j] == 1) { // �;��ٸ� ť�� �ֱ�
                Q.push({ i,j });
            }
            if (board[i][j] == 0) { //�����ʾҴٸ� 
                dist[i][j] = -1; // -1�ֱ�
            }
        }
    }
    while (!Q.empty()) { //������� ��������
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //������ ����ٸ� pass
            if (dist[nx][ny] >= 0) continue; //�������͵鸸 -1�̴�. �� �;��ų� ���ٸ� pass
            dist[nx][ny] = dist[cur.x][cur.y] + 1;
            Q.push({ nx,ny });
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] == -1) {// �������� �����Ѵٸ�
                cout << -1;
                return 0; // ���⼭ ����
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;
}

