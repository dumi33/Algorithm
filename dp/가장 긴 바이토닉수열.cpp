#include<iostream>
#include<algorithm>
using namespace std;
int n;
int arr[1001];
int dpi[1001]; //증가하는 값을 저장 할 배열
int dpd[1001]; // 감소하는 값을 저장 할 배열
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        dpi[i] = 1;
        for (int j = 1; j <= i; j++) {
            if (arr[i] > arr[j] && dpi[i] < dpi[j] + 1) {
                dpi[i] = dpi[j] + 1;
            }
        }
    }
    for (int i = n; i > 0; i--) {
        dpd[i] = 1;
        for (int j = n; j >= i; j--) {
            if (arr[i] > arr[j] && dpd[i] < dpd[j] + 1) {
                dpd[i] = dpd[j] + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dpi[i] + dpd[i]);
    }
    cout << ans - 1;
}