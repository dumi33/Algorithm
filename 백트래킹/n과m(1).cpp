#include<iostream>
using namespace std;
int n, m;
int arr[10];
bool iss[10];
void func(int k) { //arr[k]�� ���ϴ� �Լ� //k�� 0,1,2..��
    if (k == m) { //���ڰ� ���� �������ٸ� 
        for (int i = 0; i < m; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!iss[i]) { //���� i�� �ҷ������ʾҴٸ�
            arr[k] = i;
            iss[i] = 1;
            func(k + 1);
            iss[i] = 0;//��Ͱ� ������ ���ƿͼ� ���� ���� �����ش�.
        }
    }
}
int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(0);

    cin >> n >> m;
    func(0);
}