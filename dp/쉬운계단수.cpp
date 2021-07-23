#include<iostream>
using namespace std;
int dp[101][11]; //9+1을 처리하기위해 11로
//dp[n][l] -> n글자인데 l로 끝나는 수의 계단수
#define mod 1000000000 

int main() {
    int n; cin >> n;
    for (int i = 1; i < 10; i++) { // 1글자의 계단수는 1개 //1부터 9까지
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) { //2글자부터 n글자까지 
        for (int j = 0; j < 10; j++) { // 0부터 9로 끝나는
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