#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> v;
int visit[10];
int arr[10]; //저장되는 배열

void func(int dep, int prv) {
    if (dep == m) {// m글자일때 출력
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    int check[10001] = { 0 };
    for (int i = prv+1; i < n; i++) { // 인덱스를 표현
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

    func(0, -1); // 길이는 0이고 prv(이전 값)은 없으므로 -1이다.

}