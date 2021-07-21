#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
int dp[10001][3], arr[10001], n;
int func(int i, int s) { //i개를 마셨을때 연속으로 s개를 먹은 상황에서 앞으로 마실수 있는 최대값을 구하는 함수
    if (i == n+1) return 0; // n개를 전부 처리하고 n+1을 고민중인 것은 더이상 마실게 없으므로 0 
    int& ret = dp[i][s];
    if (ret != -1) return ret;

    ret = func(i + 1, 0);//안마셨을경우 -> n+1개의 포도주를 고민중. 연속으로 마사지않았음
    if (s == 0) ret = max(func(i + 1 ,1) + arr[i], ret); // 
    if (s == 1) ret = max(func(i + 1, 2) + arr[i], ret);
    return ret;
}
int main() {
    cin >> n;
    for (int i = 0; i <= n; i++) { // 모두 -1으로 초기화
        for (int j = 0; j < 3; j++) {
            dp[i][j] = -1;
        }
    }
    ;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    cout << func(0, 0); // (앞에서) 0개의 포도주를 처리했을때 
                        // 0번 포도주를 마실지 말지 고민하면서
    //앞으로 마실수 있는  최댓값
// 앞에서 아무것도 안마셨으니까 연속성이 없으므로 두번째 인수도 0이다.
}