#include<iostream>
using namespace std;
void func(int a, int b, int n) {
    if (n == 1) {
        cout << a << " " << b << "\n";
        return;
    }
    func(a, 6 - a - b, n - 1); // 1+2+3은 6이기 때문에 //n-1개를 1->2로
    cout << a << " " << b << "\n"; // n번째 원반의 이동
    func(6 - a - b, b, n - 1); // 2 -> 3으로 n-1개의 원반이 이동
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    cout << (1 << k) - 1 << '\n';
    func(1, 3, k);
}