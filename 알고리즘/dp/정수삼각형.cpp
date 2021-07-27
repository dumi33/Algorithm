#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int tri[501][501];
int sum[501][501];
int path(int y, int x) {
    if (y == n - 1) return tri[y][x];
    int& ret = sum[y][x];
    if (ret != -1) return ret;
    return ret = max(path(y + 1, x), path(y + 1, x + 1)) + tri[y][x];
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> tri[i][j];
        }
    }
    memset(sum, -1, sizeof(sum));
    cout << path(0, 0); // x와 y좌표가 (0,0)일때부터 시작
}