#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    queue<int> Q;
    int t, n;
    cin >> t;
    while (t--) {
        string st;
        cin >> st;
        if (st == "push") {
            cin >> n;
            Q.push(n);
        }
        else if (st == "pop") {
            if (Q.empty()) cout << -1 << "\n";
            else {
                cout << Q.front() << "\n";
                Q.pop();
            }
        }
        else if (st == "size") {
            cout << Q.size() << "\n";
        }
        else if (st == "empty") {
            if (Q.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if (st == "front") {
            if (Q.empty()) cout << -1 << "\n";
            else cout << Q.front() << "n";
        }
        else {
            if (Q.empty()) cout << -1 << "\n";
            else cout << Q.back() << "\n";
        }

    }
}