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
void fill(int a, int b, int c, int d) { // �־��� ������ 1�� �����.
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
        fill(a, b, c, d); // 1�� ��ȯ
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) { // ������ �ƴѰ� �߰�!
                queue<pair<int, int> >Q;
                Q.push({ i,j }); // ť�� �ִ´�.
                board[i][j] = 1; // �鷶��
                int cnt = 0;
                while (!Q.empty()) { // ť�� �������� (��, �ֺ��� 0�� �ִ°��� ����������)
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    cnt++; // 0�� ����
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //������ ��������
                        if (board[nx][ny] == 0) { // 0�ΰ� �߰�
                            board[nx][ny] = 1;
                            Q.push({ nx,ny });
                        }
                    }
                } // �� �ٹ� 0 Ž�� �Ϸ�
                v.push_back(cnt); // ������ �ִ´�.
            }
        }
    }
    cout << v.size() << "\n";
    sort(v.begin(), v.end()); // �������� ����
    for (int t : v) cout << t<<" "; 
}