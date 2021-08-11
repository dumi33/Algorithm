#include<iostream>
#include<map>
using namespace std;
map<string, string> mp;
int main() {
    int ans = 0;
    bool iron = false;
    int n, p, w, l, g;
    cin >> n >> p;
    cin >> w >> l >> g;
    for (int i = 0; i < p; i++) {
        string name, log;
        cin >> name >> log;
        mp[name] = log;
    }
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        if (mp.find(name) == mp.end()) { //없다면
            if (ans - l >= 0) {
                ans -= l;
            }
            else ans = 0;
        }
        else if (mp[name] == "W") { // 이길사람과 게임을 했다면
            ans += w;
            if (ans >= g) iron = true;
        }
        else if (mp[name] == "L") {
            if (ans - l >= 0) {
                ans -= l;
            }
            else ans = 0;
        }


    }
    if (iron) {
        cout << "I AM NOT IRONMAN!!";
    }
    else {
        cout << "I AM IRONMAN!!";
    }
}