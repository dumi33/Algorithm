#include<iostream>
using namespace std;
int arr[64][64];
void compress(int n, int y, int x) { // ������
    if (n == 1) {
        cout << arr[y][x];
        return;
    }
    bool iszero = true, isone = true;
    for (int i = y; i < y + n; i++) {
        for (int j = x; j < x + n; j++) {
            if (arr[i][j]) {
                iszero = false;
            }
            else isone = false;
        }
    }
    if (iszero) cout << 0;
    else if (isone) cout << 1;
    else {
        cout << "(";
        compress(n / 2, y, x); // 2��и�
        compress(n / 2, y, x + n / 2); // 1��и�
        compress(n / 2, y + n / 2, x); // 3��и�
        compress(n / 2, y + n / 2, x + n / 2); // 4��и�
        cout << ")";
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) {
            arr[i][j] = str[j] - '0';
        }
        
    }
    compress(n, 0, 0);
}