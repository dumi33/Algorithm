#include<iostream>
using namespace std;
int n;
int queen_loc[15];//퀸의 위치저장배열
//queen_loc[3]=2 라면 3행 2열에 퀸이 있다.
int cnt;
bool check(int row) { //여기에 놓아도 되니?
     //입력받은 행까지 탐색
    //같은 열, 대각선에 퀸이 있으면 0을 반환
    for (int i = 0; i < row; i++) {
        if (queen_loc[row] == queen_loc[i] || (row - i == abs(queen_loc[row] - queen_loc[i]))) {
            return 0;
        }
    }
    return 1;
}
void nqueen(int row) { // row에 놓아보겠다.
    if (row == n) cnt++;  //마지막행까지 왔다면
    else {
        for (int col = 0; col < n; col++) { //모든 열에 대해서
            queen_loc[row] = col;
            if (check(row)) nqueen(row + 1);
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    nqueen(0); // 0행에 퀸을 놓아보겠다.
    cout << cnt;
}