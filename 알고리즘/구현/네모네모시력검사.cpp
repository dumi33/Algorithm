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
            else arr[i][j] = 1; // #�ϰ��
        }
    }
    bool stop = false;
    for (int i = 0; i < n && stop == false; i++) { //break�� �ٱ����� ������
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) { // #�� ������
                sy = i; sx = j;
                stop = true;
                break; // ���� ����(for)�� ������. 
            }
        }
    }
    stop = false;
    for (int i = n - 1; i >= 0 && stop == false; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (arr[i][j] == 1) { // #�� ������
                ey = i; ex = j;
                stop = true;
                break;
            }
        }
    }
    int y = ey - sy + 1;
    int x = ex - sx + 1;
    

    //left�� right Ȯ���ϱ�
    for (int i = sy; i <= ey; i++) {
        if (arr[i][sx]) { // #�� �ִٸ�
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
    //up�� down Ȯ���ϱ�
    for (int i = sx; i <= ex; i++) {
        if (arr[sy][i]) { // #�� �ִٸ�
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