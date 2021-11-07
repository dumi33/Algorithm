#include<iostream>
using namespace std;
int col[16], cross1[30], cross2[30];//15*2-1 = 29이므로 약 30
int cnt, n;

bool check(int r, int c) { // 놓을 수 있는 자리인가
	if (col[c] || cross1[r + c] || cross2[r - c + n - 1]) return false;
	return true;
}

void queen(int row) { //row 행에 퀸 놓을 자리 찾기 
	if (row == n) {// 방법 하나 발견!
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
	queen(0); // 1행에 놓을 자리 찾기
	cout << cnt;
}