#include<iostream>
#include<vector>
#include<algorithm>
#define X first
#define Y second
using namespace std;
vector<pair<int, int> > cctv; // cctv�� ��ǥ ���� 

int n, m, mn;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int mp1[10][10]; // ���ʿ� �Է¹���
int mp2[10][10]; // �簢������ ���� ����


bool Bound(int a, int b) { // ������ �Ѿ�� 1�� ��ȯ
	return a < 0 || a >= n || b < 0 || b >= m;
}

void upd(int x, int y, int dir) { // (x,y)�������� dir�������� ���� ������ ������ ��ĭ�� 7�� ����
	dir %= 4; // dir�� 0���� 3������ 
	while (1) {
		x += dx[dir]; // dir �������� �� ����.
		y += dy[dir];
		if (Bound(x, y) || mp2[x][y] == 6) return; // ���̰ų�, ����ٸ� upd�� Ż��
		if (mp2[x][y] != 0) continue; // cctv�� ��� pass // cctv�� 7���� ����� �ȵǴϱ�
		mp2[x][y] = 7; // ��ĭ�� �����ִٴ� �ǹ̷� 7�� �����.
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mp1[i][j];
			if (mp1[i][j] != 0 && mp1[i][j] != 6) cctv.push_back({ i,j }); // cctv�� ��ġ�� �ִ´�.
			if (mp1[i][j] == 0) mn++; // ��ĭ�� ���� ����
		}
	}
	for (int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++){ // 4^(cctv.size)��ŭ
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				mp2[i][j] = mp1[i][j]; 
			}
		}

		int brute = tmp;
		for (int i = 0; i < cctv.size(); i++) {
			int dir = brute % 4; //0~3������ 
			brute /= 4;
			int x = cctv[i].X;
			int y = cctv[i].Y;
			if (mp1[x][y] == 1) {
				upd(x, y, dir);
			}
			else if (mp1[x][y] == 2) {
				upd(x, y, dir); 
				upd(x, y, dir+2); // ���̸� ����, ���̸� ������
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