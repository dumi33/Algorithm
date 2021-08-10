#include <iostream>
#include <map>

using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    map <ll, int> mp;
    map <ll, int> mp_result;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        ll num1; cin >> num1;
        if (mp.find(num1) == mp.end()) { // 못찾았다면 //처음 들어왔다면
            mp[num1] = 1;
        }
    }

    for (int i = 0; i < m; i++) {
        ll num2; cin >> num2;
        if (mp.find(num2) == mp.end()) { // 못찾았다면 //처음 들어왔다면
            mp_result[num2] = 1;
        }
        else mp[num2] = 0;
    }
    for (auto i : mp) {
        if (i.second != 0) {
            mp_result[i.first] = i.second;
        }
    }

    for (auto i : mp_result) {
        sum += i.second;
    }
    cout << sum;
}