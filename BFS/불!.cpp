#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
string board[1002]; //�̷θ� ����
int dist1[1002][1002]; //���� �ð��� ����
int dist2[1002][1002]; //�������� �ð��� ����
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
#define x first
#define y second
int main() {
    queue<pair<int, int> >Q1;
    queue<pair<int, int> >Q2;
    int R, C;
    cin >> R >> C;
    for (int i = 0; i < R; i++) { //��� �Ÿ��� -1�� �ʱ�ȭ
        fill(dist1[i], dist1[i] + C, -1);
        fill(dist2[i], dist2[i] + C, -1);
    }
    for (int i = 0; i < R; i++) {
        cin >> board[i]; //�̷θ� �Է¹���
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 'F') {
                Q1.push({ i,j });
                dist1[i][j] = 0;// �װ����� ��������
            }
            if (board[i][j] == 'J') {
                Q2.push({ i,j });
                dist2[i][j] = 0;
            }
        }
    }
    //  ���� BFS
    while (!Q1.empty()) { //���� ������ ����������
        pair<int, int> cur = Q1.front();
        Q1.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || nx >= R || nx < 0 || ny >= C) continue; //���� ����� pass
            if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            //�̹� �ͺðų� #(��)�̸� pass
            dist1[nx][ny] = dist1[cur.x][cur.y] + 1;
            Q1.push({ nx,ny });
        }

    } // �������� BFS 
    while (!Q2.empty()) { //���� ������ ����������
        pair<int, int> cur = Q2.front();
        Q2.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                cout << dist2[cur.x][cur.y] + 1; // 0���� �����Ͽ��⿡ +1�� ���ش�.
                return 0; // Ż�⼺��
            }
            if (dist2[nx][ny] >= 0 || board[nx][ny] == '#')continue;
            //�̹� �ͺðų� #(��)�̸� pass
            if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.x][cur.y] + 1) {
                continue;
            } // ���� �����̺��� �����ٸ� pass
            dist2[nx][ny] = dist2[cur.x][cur.y] + 1;
            Q2.push({ nx,ny });
        }
    }
    cout << "IMPOSSIBLE";
}