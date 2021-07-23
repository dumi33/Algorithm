#include<iostream>
using namespace std;
int dp[101][11]; //9+1�� ó���ϱ����� 11��
//dp[n][l] -> n�����ε� l�� ������ ���� ��ܼ�
#define mod 1000000000 

int main() {
    int n; cin >> n;
    for (int i = 1; i < 10; i++) { // 1������ ��ܼ��� 1�� //1���� 9����
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) { //2���ں��� n���ڱ��� 
        for (int j = 0; j < 10; j++) { // 0���� 9�� ������
            if (j == 0)  dp[i][j] = (dp[i - 1][j + 1]) % mod;
            else if (j == 9)  dp[i][j] = (dp[i - 1][j - 1]) % mod;
            else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
        }
    }
    int sum = 0;
    for (int i = 0; i <= 9; i++) {
        sum = (sum + dp[n][i]) % mod;
    }
    cout << sum;
}