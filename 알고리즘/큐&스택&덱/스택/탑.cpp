#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int n, num;
int arr[500001];
int ans[500001]; // 0으로 채워져있음

stack<int> s;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        arr[i] = num;
    }
    for (int i = n; i > 0; i--) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}



