#include<iostream>
#include<vector>
using namespace std;
vector<string> v;
void check(string c) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < c.size(); j++) {
            if (c == v[i]) return; //같은 단어임
            c += c.at(0);
            c.erase(0, 1);
        }
        
    }
    v.push_back(c);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (v.size() == 0) v.push_back(str);
        else check(str);
    }
    cout << v.size();
}
