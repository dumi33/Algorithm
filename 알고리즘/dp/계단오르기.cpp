#include<iostream>
#include<algorithm>
using namespace std;

int arr[301][3];

int main() {

	int n; cin >> n;
	for (int i = 1; i <= n; i++)  cin >> arr[i][0]; // �Էµ� �迭
	arr[1][1] = arr[1][0];
	arr[2][1] = arr[2][0];
	arr[1][2] = 0;
	arr[2][2] = arr[2][0] + arr[1][0];
	arr[2][0] = arr[2][2];

	for (int i = 3; i <n; i++) { // ���̺��� ��� ���ŵǵ���  // ������ n�� ���� 
			arr[i][1] =arr[i - 2][0]+ arr[i][0]; // +1 ����� ���[�������� 1���]
			arr[i][2] = arr[i - 1][1] + arr[i][0]; // +2 ����� ���[�������� 2���] //���� ����� ���� ���

			arr[i][0] = max(arr[i][1], arr[i][2]);
	}
	if (n < 3) { // ��� Ʋ���� ����  // �̹� ������ n==2�϶� arr[n][0]�� �����ߴµ� �ؿ� ��¹����� ���ϴϱ� Ʋ�� 
		cout << arr[n][0]; return 0;
	}
	cout << arr[n][0] + max(arr[n - 1][1], arr[n - 2][0]);
	
}