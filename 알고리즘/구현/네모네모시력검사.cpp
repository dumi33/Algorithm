#include<iostream>
using namespace std;
int LEFT, RIGHT, UP, DOWN;
int arr[101][101];
char c;
int sx, sy, ex, ey;
int main() {
    int n, m; cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            if (c == '.') arr[i][j] = 0;
            else arr[i][j] = 1; // #일경우
        }
    }
    bool stop = false;
    for (int i = 0; i < n && stop == false; i++) { //break가 바깥쪽은 못끝냄
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) { // #이 나오면
                sy = i; sx = j;
                stop = true;
                break; // 안쪽 루프(for)만 끝낸다. 
            }
        }
    }
    stop = false;
    for (int i = n - 1; i >= 0 && stop == false; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (arr[i][j] == 1) { // #이 나오면
                ey = i; ex = j;
                stop = true;
                break;
            }
        }
    }
    int y = ey - sy + 1;
    int x = ex - sx + 1;
    

    //left와 right 확인하기
    for (int i = sy; i <= ey; i++) {
        if (arr[i][sx]) { // #이 있다면
            LEFT++;
        }
        if (arr[i][ex]) {
            RIGHT++;
        }
    }
    
    if (y != LEFT) {
        cout << "LEFT"; return 0;
    }
    if (y != RIGHT) {
        cout << "RIGHT";  return 0;
    }
    //up와 down 확인하기
    for (int i = sx; i <= ex; i++) {
        if (arr[sy][i]) { // #이 있다면
            UP++;
        }
        if (arr[ey][i]) {
            DOWN++;
        }
    }
    if (x != UP) {
        cout << "UP"; return 0;
    }
    if (x != DOWN) {
        cout << "DOWN";  return 0;
    }

}