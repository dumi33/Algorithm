#include<iostream>
#include<algorithm>
int t[1001];
int p[1001];
int dp[1001];
using namespace std;
int main() {
    int n, next;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }
    for (int i = n; i > 0; i--) { //������������ �ٿ�����.
        next = i + t[i]; //��¥ + �ҿ�ð� ��, ���� ����ĥ�ð�
        if (next > n + 1) {//���� ����ĥ�ð��� ��糯¥���� ��� ���� �Ҽ������Ƿ�
            dp[i] = dp[i + 1]; //������ ���� �ִ��� i�� dp������
        }
        else {
            dp[i] = max(dp[i + 1], dp[next] + p[i]);//������ ���� �ִ� �Ǵ�
            //���� ����ĥ ��¥�� dp�� + �ش糯¥�� ������ ���Ͽ� ū��
        }
    }
    cout << dp[1] << "\n";
}