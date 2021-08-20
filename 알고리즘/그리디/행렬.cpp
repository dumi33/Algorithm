#include<iostream>
using namespace std;
int arr[51][51];
char c;
int cnt;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            arr[i][j] = c - '0'; //연속으로 들어올때 이렇게 받아야함
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c; int temp = c - '0';
            if (temp != arr[i][j]) arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }
    //크기가 3*3보다 작다면
    if (n < 3 || m < 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j]) { // 뒤집을수없는데 다른게 있으먄
                    cout << -1;
                    return 0;
                }
            }
        }
        cout << 0;
    }
    else { //크기가 3*3보다 크다면
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (arr[i][j]) { // 다를때
                    if (i <= n - 3 && j <= m - 3) { // 뒤집을수 있는 상황이라면
                        for (int x = i; x < i + 3; x++) {
                            for (int y = j; y < j + 3; y++) {
                                arr[x][y] = !arr[x][y]; // 뒤집기
                            }
                        }
                        cnt++;
                    }
                    else { // 다른데 뒤집을 수 없다면?
                        cout << -1; return 0;
                    }
                }
            }
        }
        cout << cnt;
    }

}