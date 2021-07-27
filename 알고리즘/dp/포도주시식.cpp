#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
int dp[10001][3], arr[10001], n;
int func(int i, int s) { //i���� �������� �������� s���� ���� ��Ȳ���� ������ ���Ǽ� �ִ� �ִ밪�� ���ϴ� �Լ�
    if (i == n+1) return 0; // n���� ���� ó���ϰ� n+1�� ������� ���� ���̻� ���ǰ� �����Ƿ� 0 
    int& ret = dp[i][s];
    if (ret != -1) return ret;

    ret = func(i + 1, 0);//�ȸ�������� -> n+1���� �����ָ� �����. �������� �������ʾ���
    if (s == 0) ret = max(func(i + 1 ,1) + arr[i], ret); // 
    if (s == 1) ret = max(func(i + 1, 2) + arr[i], ret);
    return ret;
}
int main() {
    cin >> n;
    for (int i = 0; i <= n; i++) { // ��� -1���� �ʱ�ȭ
        for (int j = 0; j < 3; j++) {
            dp[i][j] = -1;
        }
    }
    ;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    cout << func(0, 0); // (�տ���) 0���� �����ָ� ó�������� 
                        // 0�� �����ָ� ������ ���� ����ϸ鼭
    //������ ���Ǽ� �ִ�  �ִ�
// �տ��� �ƹ��͵� �ȸ������ϱ� ���Ӽ��� �����Ƿ� �ι�° �μ��� 0�̴�.
}