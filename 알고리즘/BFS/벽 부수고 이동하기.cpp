#include<iostream>
#include<queue>


using namespace std;
int mp[1001][1001];
int dis[1001][1001][2]; // �湮ǥ�� + �Ÿ� ����  // �ϳ��� ���� �μ��� ���� [1] // 3�������� ǥ��
int n, m;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
struct T {
	int x, y, wall; //wall �� 0 �̸� �ȱ���, 1�̸� ����
};
queue<T> q;

int bfs() {
	dis[0][0][0] = 1; // ������ �湮  //������ ���� count�ϹǷ� 1�� �־���
	q.push({ 0,0,0 }); // ť�� ����

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int wall = q.front().wall;
		q.pop();


		if (x == n - 1 && y == m - 1) return dis[x][y][wall]; //Ż��

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (ny < 0 || nx < 0 || nx >= n || ny >= m) continue;
			if (dis[nx][ny][wall] == 0) { //�Ȱ�����
				if (mp[nx][ny] == 0) { // �����ִ°�
					dis[nx][ny][wall] = dis[x][y][wall] + 1;
					q.push({ nx,ny,wall });
				}
				else if (wall == 0) { //���� ������ ���ٸ� // ���� �ְ�
					dis[nx][ny][1] = dis[x][y][0] + 1;
					q.push({ nx,ny,1 });
				}
			}
		}
	}
	return -1;
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	string tmp;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			mp[i][j] = tmp[j] - '0'; // string�� int ������
		}
	}
	cout << bfs();
}