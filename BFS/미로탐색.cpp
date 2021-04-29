#include<iostream>
#include<queue>
#include<string>
using namespace std;
#define x first
#define y second
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
string board[102]; //0�� 1�� ����
int dist[102][102]; //�Ÿ�����
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = -1; //�Ÿ��� -1�� ��� �ʱ�ȭ
        }
    }
    queue<pair<int, int> > Q; //2���� int�� queue�� �����.
    Q.push({ 0,0 }); //���� ���
    dist[0][0] = 0; //���� ó���� 0���� �Ѵ�.
    while (!Q.empty()) { //��������������� -> (������ ��������)
        pair<int, int> cur = Q.front();//2���� int pair�� ����(?) cur�� ����� front�� �����Ѵ�.
        Q.pop();
        for (int dis = 0; dis < 4; dis++) {
            int nx = cur.x + dx[dis];
            int ny = cur.y + dy[dis];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 0���� �۰ų� n,m ���� Ŭ���� for���� �������� �Ѿ��.
            if (dist[nx][ny] >= 0 || board[nx][ny] != '1')continue; // �̹� �Դ����̰ų� 1�� �ƴҰ�� pass
            dist[nx][ny] = dist[cur.x][cur.y] + 1;
            Q.push({ nx,ny });
        }

    }
    cout << dist[n - 1][m - 1] + 1;
}

