#include<iostream>
int arr[10];
int iss[10];
int n, m;

using namespace std;
void func(int k, int pre) {
    if (k == m) {
        for (int i = 0; i < m; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!iss[i] && pre < i) {
            arr[k] = i;
            iss[i] = 1;
            func(k + 1, i);
            iss[i] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    cin >> n >> m;
    func(0, 0);
}