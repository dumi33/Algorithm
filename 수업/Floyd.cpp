#include <iostream>

#include <algorithm>

using namespace std;
#define inf 100000
const int MAX = 100;
int n;
int D[MAX][MAX] = { //큰값을 inf로 define하였다.
	{0,0,0,0,0,0},
	{0,0,1,inf,1,5},
	{0,9,0,3,2,inf},
	{0,inf,inf,0,4,inf},
	{0,inf,inf,2,0,3},
	{0, 3,inf,inf,inf,0},
};
int p[MAX][MAX];
void floyd();
void path(int q, int r);

int main() {
	cin >> n;
	cout << "\n";
	floyd();
	cout << "D[i][j] is \n"; // 최종 D를 출력한다.
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << D[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n\n";

	cout << "P[i][j] is \n"; //PATH를 출력한다.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << p[i][j]<<" ";
		}
		cout << "\n";
	}
	cout << "\n\n";
	int a,b;
	for (int i = 0; i < 3; i++) { //3번 반복한다.
		cout << "구하고 싶은 최단경로의 시작노드와 끝노드를 입력하시오\n";
		cin >> a >> b;
		cout << "The shortest path : ";
		cout << "v" << a; //시작노드
		path(a, b);
		cout << " v" << b << "\n\n"; // 끝노드
	}
	
	cout << "정보통신공학과_12191728_김두미";
}
void floyd() {
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (D[i][j] > D[i][k] + D[k][j]) { // 원래 경로가 새롭게 k노드를 경유할때보다 크다면
					D[i][j] = D[i][k] + D[k][j]; // 새롭게 k노드를 경유한 비용을 넣는다.
					p[i][j] = k; //경유점을 P배열에 넣는다
				}
			}
		}
	}
}
void path(int q, int r) {
	if (p[q][r] != 0) { // 다른 노드를 경유를 했다면
		path(q, p[q][r]); //시작노드에서 경유한 노드까지의 경유 경로를 재귀를 이용해 확인한다. 
		cout << " v" << p[q][r]; // 출력
		path(p[q][r], r); // 경유한 노드부터 마지막 노드까지의 경유 경로를 재귀를 이용해 확인한다.
	}
}