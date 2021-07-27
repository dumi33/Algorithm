#include<iostream>
using namespace std;
int n, m;
int arr[10];
bool iss[10];
void func(int k) { //arr[k]를 정하는 함수 //k는 0,1,2..임
    if (k == m) { //숫자가 전부 정해졌다면 
        for (int i = 0; i < m; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!iss[i]) { //숫자 i가 불려지지않았다면
            arr[k] = i;
            iss[i] = 1;
            func(k + 1);
            iss[i] = 0;//재귀가 끝난후 돌아와서 썻던 것을 지워준다.
        }
    }
}
int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(0);

    cin >> n >> m;
    func(0);
}