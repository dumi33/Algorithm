#include<iostream>
#include<queue>


using namespace std;
int mp[1001][1001];
int dis[1001][1001][2]; // 방문표시 + 거리 측정  // 하나의 벽이 부서진 곳을 [1] // 3차원으로 표시
int n, m;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
struct T {
	int x, y, wall; //wall 이 0 이면 안깨진, 1이면 깨진
};
queue<T> q;

int bfs() {
	dis[0][0][0] = 1; // 시작점 방문  //시작점 부터 count하므로 1을 넣어줌
	q.push({ 0,0,0 }); // 큐에 삽입

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int wall = q.front().wall;
		q.pop();


		if (x == n - 1 && y == m - 1) return dis[x][y][wall]; //탈출

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (ny < 0 || nx < 0 || nx >= n || ny >= m) continue;
			if (dis[nx][ny][wall] == 0) { //안가본곳
				if (mp[nx][ny] == 0) { // 갈수있는곳
					dis[nx][ny][wall] = dis[x][y][wall] + 1;
					q.push({ nx,ny,wall });
				}
				else if (wall == 0) { //벽을 깨본적 없다면 // 벽이 있고
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
			mp[i][j] = tmp[j] - '0'; // string을 int 형으로
		}
	}
	cout << bfs();
}