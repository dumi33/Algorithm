#include<iostream>
using namespace std;
int col[16], cross1[30], cross2[30];//15*2-1 = 29�̹Ƿ� �� 30
int cnt, n;

bool check(int r, int c) { // ���� �� �ִ� �ڸ��ΰ�
	if (col[c] || cross1[r + c] || cross2[r - c + n - 1]) return false;
	return true;
}

void queen(int row) { //row �࿡ �� ���� �ڸ� ã�� 
	if (row == n) {// ��� �ϳ� �߰�!
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (check(row, i)) {
			col[i] = 1;
			cross1[row + i] = 1;
			cross2[row - i + n - 1] = 1;
			queen(row + 1);
			col[i] = 0;
			cross1[row + i] = 0;
			cross2[row - i + n - 1] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	queen(0); // 1�࿡ ���� �ڸ� ã��
	cout << cnt;
}