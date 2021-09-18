#include<iostream>
#include<vector>
#include<algorithm>
#define X first
#define Y second
using namespace std;
vector<pair<int, int> > cctv; // cctv의 좌표 저장 

int n, m, mn;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int mp1[10][10]; // 최초에 입력받은
int mp2[10][10]; // 사각지대의 개수 세기


bool Bound(int a, int b) { // 범위를 넘어가면 1을 반환
	return a < 0 || a >= n || b < 0 || b >= m;
}

void upd(int x, int y, int dir) { // (x,y)에서부터 dir방향으로 벽을 만나기 전까지 빈칸을 7로 만듬
	dir %= 4; // dir은 0에서 3까지만 
	while (1) {
		x += dx[dir]; // dir 방향으로 쭉 간다.
		y += dy[dir];
		if (Bound(x, y) || mp2[x][y] == 6) return; // 벽이거나, 벗어났다면 upd를 탈출
		if (mp2[x][y] != 0) continue; // cctv의 경우 pass // cctv는 7으로 만들면 안되니까
		mp2[x][y] = 7; // 빈칸을 볼수있다는 의미로 7로 만든다.
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mp1[i][j];
			if (mp1[i][j] != 0 && mp1[i][j] != 6) cctv.push_back({ i,j }); // cctv의 위치를 넣는다.
			if (mp1[i][j] == 0) mn++; // 빈칸의 개수 세기
		}
	}
	for (int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++){ // 4^(cctv.size)만큼
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				mp2[i][j] = mp1[i][j]; 
			}
		}

		int brute = tmp;
		for (int i = 0; i < cctv.size(); i++) {
			int dir = brute % 4; //0~3까지만 
			brute /= 4;
			int x = cctv[i].X;
			int y = cctv[i].Y;
			if (mp1[x][y] == 1) {
				upd(x, y, dir);
			}
			else if (mp1[x][y] == 2) {
				upd(x, y, dir); 
				upd(x, y, dir+2); // 동이면 서로, 북이면 남으로
			}
			else if (mp1[x][y] == 3) {
				upd(x, y, dir);
				upd(x, y, dir + 1); 
			}
			else if (mp1[x][y] == 4) {
				upd(x, y, dir);
				upd(x, y, dir + 1);
				upd(x, y, dir + 2); 
			}
			else if (mp1[x][y] == 5) {
				upd(x, y, dir);
				upd(x, y, dir + 1);
				upd(x, y, dir + 2);
				upd(x, y, dir + 3);
			}
		}
		int val = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mp2[i][j] == 0) val++;
			}
		}
		mn = min(mn, val);
	}
	cout << mn;
	
}