#include<iostream>
using namespace std;
int arr[7];
int n;
int isu[50];
int use[14];
void func(int k) {
    if (k == 6) {
        for (int i = 0; i < 6; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!isu[use[i]] && arr[k-1]<use[i]) {
            arr[k] = use[i];
            isu[use[i]] = 1;
            func(k + 1);
            isu[use[i]] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    for (;;) {
        cin >> n;
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            cin >> use[i];
        }
        func(0);
    }
        
    
}