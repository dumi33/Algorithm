#include<iostream>
#include<vector>
using namespace std;
int n, k, cnt;
void func(vector<int>& v, int sum) {
    if (sum > n) return;
    if (sum == n) {
        cnt++;
        if (cnt == k) {
            for (int i = 0; i < v.size(); i++) {
                if (i == v.size() - 1) cout << v[i];
                else cout << v[i] << "+";
            }
        }
        return;
    }
    for (int i = 1; i <= 3; i++) {
        v.push_back(i);
        func(v, sum + i);
        v.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    vector<int> v;
    func(v, 0);
    if (cnt == 0 || cnt < k) cout << "-1";
}