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
            arr[i][j] = c - '0'; //�������� ���ö� �̷��� �޾ƾ���
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c; int temp = c - '0';
            if (temp != arr[i][j]) arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }
    //ũ�Ⱑ 3*3���� �۴ٸ�
    if (n < 3 || m < 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j]) { // �����������µ� �ٸ��� ������
                    cout << -1;
                    return 0;
                }
            }
        }
        cout << 0;
    }
    else { //ũ�Ⱑ 3*3���� ũ�ٸ�
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (arr[i][j]) { // �ٸ���
                    if (i <= n - 3 && j <= m - 3) { // �������� �ִ� ��Ȳ�̶��
                        for (int x = i; x < i + 3; x++) {
                            for (int y = j; y < j + 3; y++) {
                                arr[x][y] = !arr[x][y]; // ������
                            }
                        }
                        cnt++;
                    }
                    else { // �ٸ��� ������ �� ���ٸ�?
                        cout << -1; return 0;
                    }
                }
            }
        }
        cout << cnt;
    }

}