#include<iostream>
using namespace std;
int n, q, s, b;
int cnt, num[1000];

int check(int i, int q, int s, int b) {
	int s_cnt = 0, b_cnt = 0;
	int i_1 = i / 100, i_2 = (i % 100) / 10, i_3 = (i % 100) % 10;
	int q_1 = q / 100, q_2 = (q % 100) / 10, q_3 = (q % 100) % 10;

	if (i_1 == 0 || i_2 == 0 || i_3 == 0 || i_2 == i_1 || i_2 == i_3 || i_1 == i_3) return 1;

	if (i_1 == q_1) s_cnt++;
	if (i_2 == q_2) s_cnt++;
	if (i_3 == q_3) s_cnt++;

	if (q_1 == i_2 || q_1 == i_3) b_cnt++;
	if (q_2 == i_1 || q_2 == i_3) b_cnt++;
	if (q_3 == i_2 || q_3 == i_1) b_cnt++;

	if (s_cnt == s && b_cnt == b) return 0; // 맞으면 return 0 

	return 1; // 틀리면 return 1
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);


	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> q >> s >> b;
		for (int i = 123; i <= 987; i++) {
			if (num[i] == 0) { //맞을 가능성이 있는 친구
				num[i] = check(i, q, s, b);
			}

		}
	}
	for (int i = 123; i <= 987; i++) {
		if (num[i] == 0) {
			cnt++;
		}
	}
	cout << cnt;
}