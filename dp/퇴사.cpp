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
    for (int i = n; i > 0; i--) { //마지막날부터 줄여간다.
        next = i + t[i]; //날짜 + 소요시간 즉, 일을 끝마칠시간
        if (next > n + 1) {//일을 끝마칠시간이 퇴사날짜보다 길면 일을 할수없으므로
            dp[i] = dp[i + 1]; //이전에 구한 최댓값을 i의 dp값으로
        }
        else {
            dp[i] = max(dp[i + 1], dp[next] + p[i]);//이전에 구한 최댓값 또는
            //일을 끝마칠 날짜의 dp값 + 해당날짜의 수당을 비교하여 큰것
        }
    }
    cout << dp[1] << "\n";
}