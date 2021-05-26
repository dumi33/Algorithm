#include <iostream>

#include <algorithm>

using namespace std;
#define inf 100000
const int MAX = 100;
int n;
int D[MAX][MAX] = { //ū���� inf�� define�Ͽ���.
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
	cout << "D[i][j] is \n"; // ���� D�� ����Ѵ�.
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << D[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n\n";

	cout << "P[i][j] is \n"; //PATH�� ����Ѵ�.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << p[i][j]<<" ";
		}
		cout << "\n";
	}
	cout << "\n\n";
	int a,b;
	for (int i = 0; i < 3; i++) { //3�� �ݺ��Ѵ�.
		cout << "���ϰ� ���� �ִܰ���� ���۳��� ����带 �Է��Ͻÿ�\n";
		cin >> a >> b;
		cout << "The shortest path : ";
		cout << "v" << a; //���۳��
		path(a, b);
		cout << " v" << b << "\n\n"; // �����
	}
	
	cout << "������Ű��а�_12191728_��ι�";
}
void floyd() {
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (D[i][j] > D[i][k] + D[k][j]) { // ���� ��ΰ� ���Ӱ� k��带 �����Ҷ����� ũ�ٸ�
					D[i][j] = D[i][k] + D[k][j]; // ���Ӱ� k��带 ������ ����� �ִ´�.
					p[i][j] = k; //�������� P�迭�� �ִ´�
				}
			}
		}
	}
}
void path(int q, int r) {
	if (p[q][r] != 0) { // �ٸ� ��带 ������ �ߴٸ�
		path(q, p[q][r]); //���۳�忡�� ������ �������� ���� ��θ� ��͸� �̿��� Ȯ���Ѵ�. 
		cout << " v" << p[q][r]; // ���
		path(p[q][r], r); // ������ ������ ������ �������� ���� ��θ� ��͸� �̿��� Ȯ���Ѵ�.
	}
}