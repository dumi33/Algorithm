#include<iostream>
using namespace std;
int n;
int queen_loc[15];//���� ��ġ����迭
//queen_loc[3]=2 ��� 3�� 2���� ���� �ִ�.
int cnt;
bool check(int row) { //���⿡ ���Ƶ� �Ǵ�?
     //�Է¹��� ����� Ž��
    //���� ��, �밢���� ���� ������ 0�� ��ȯ
    for (int i = 0; i < row; i++) {
        if (queen_loc[row] == queen_loc[i] || (row - i == abs(queen_loc[row] - queen_loc[i]))) {
            return 0;
        }
    }
    return 1;
}
void nqueen(int row) { // row�� ���ƺ��ڴ�.
    if (row == n) cnt++;  //����������� �Դٸ�
    else {
        for (int col = 0; col < n; col++) { //��� ���� ���ؼ�
            queen_loc[row] = col;
            if (check(row)) nqueen(row + 1);
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    nqueen(0); // 0�࿡ ���� ���ƺ��ڴ�.
    cout << cnt;
}