#include<iostream>
#include<algorithm>
using namespace std;

int arr[301][3];

int main() {

	int n; cin >> n;
	for (int i = 1; i <= n; i++)  cin >> arr[i][0]; // 입력된 배열
	arr[1][1] = arr[1][0];
	arr[2][1] = arr[2][0];
	arr[1][2] = 0;
	arr[2][2] = arr[2][0] + arr[1][0];
	arr[2][0] = arr[2][2];

	for (int i = 3; i <n; i++) { // 테이블이 계속 갱신되도록  // 무조건 n을 밟음 
			arr[i][1] =arr[i - 2][0]+ arr[i][0]; // +1 계단의 경우[연속으로 1계단]
			arr[i][2] = arr[i - 1][1] + arr[i][0]; // +2 계단의 경우[연속으로 2계단] //이전 계단을 오른 경우

			arr[i][0] = max(arr[i][1], arr[i][2]);
	}
	if (n < 3) { // 계속 틀리던 이유  // 이미 위에서 n==2일때 arr[n][0]을 갱신했는데 밑에 출력문에서 더하니까 틀림 
		cout << arr[n][0]; return 0;
	}
	cout << arr[n][0] + max(arr[n - 1][1], arr[n - 2][0]);
	
}