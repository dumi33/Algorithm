#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> v;
int visit[10];
int arr[10]; //����Ǵ� �迭

void func(int dep, int prv) {
    if (dep == m) {// m�����϶� ���
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    int check[10001] = { 0 };
    for (int i = prv+1; i < n; i++) { // �ε����� ǥ��
        if ( check[v[i]] == 0) {
            check[v[i]] = 1;
            arr[dep] = v[i];
            func(dep + 1, i);
            
        }
    }

}
int main() {
    cin >> n >> m;
    v.resize(n);
    for (int& i : v) cin >> i;
    sort(v.begin(), v.end());

    func(0, -1); // ���̴� 0�̰� prv(���� ��)�� �����Ƿ� -1�̴�.

}