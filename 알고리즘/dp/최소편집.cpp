#include<iostream>
#include<string>
#include<algorithm>
int arr[1001][1001];
using namespace std;
int main() {
    string s, t;
    cin >> s >> t;
    for (int i = 0; i <= s.size(); i++) {
        arr[i][0] = i;
    }
    for (int j = 0; j <= t.size(); j++) {
        arr[0][j] = j;
    }
    for (int j = 1; j <= t.size(); j++) {
        for (int i = 1; i <= s.size(); i++) {
            if (s[i-1] == t[j-1])  arr[i][j] = arr[i - 1][j - 1];
            else arr[i][j] = min(arr[i - 1][j - 1] + 1, min(arr[i][j - 1] + 1, arr[i - 1][j] + 1));
        }
    }
    cout << arr[s.size()][t.size()];
}