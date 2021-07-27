#include<iostream>
#include<algorithm>
using namespace std;
int one, zero;
string s;
int main() {
    cin >> s;
    if (s[0] == '0') zero++;
    else one++;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            if (s[i] == '1') one++;
            else zero++;
        }
    }
    cout << min(zero, one);
}

