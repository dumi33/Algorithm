#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>

using namespace std;
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int board[102][102][102];
int dist[102][102][102];
queue<tuple<int, int, int>> Q;
int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    int n, m,h;
    cin >> m >> n >> h;

    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[i][j][k]; // �;����� ���;����� ������ �Է¹ޱ�
                if (board[i][j][k] == 1) { // �;��ٸ� ť�� �ֱ�
                    Q.push({ i,j,k });
                }
                if (board[i][j][k] == 0) { //�����ʾҴٸ� 
                    dist[i][j][k] = -1; // -1�ֱ�
                }
            }
        }
    }

    while (!Q.empty()) { //������� ��������
        tuple<int, int, int> cur = Q.front();
        Q.pop();
        int curx, cury, curz;
        tie(curx, cury, curz) = cur;
        for (int dir = 0; dir < 6; dir++) {
            int nx = curx + dx[dir];
            int ny = cury + dy[dir];
            int nz = curz + dz[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue; //������ ����ٸ� pass
            if (dist[nx][ny][nz] >= 0) continue; //�������͵鸸 -1�̴�. �� �;��ų� ���ٸ� pass
            dist[nx][ny][nz] = dist[curx][cury][curz] + 1;
            Q.push({ nx,ny,nz });
        }
    }
    int ans = 0;
    for (int k =0 ; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dist[i][j][k] == -1) {// �������� �����Ѵٸ�
                    cout << -1;
                    return 0; // ���⼭ ����
                }
                ans = max(ans, dist[i][j][k]);
            }
        }
    }

    cout << ans;
}