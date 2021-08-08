#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main() {
    int n; cin >> n;
    set<string> s;
    while (n--) {
        string name, log;
        cin >> name >> log;
        if (log == "enter") s.insert(name); // 들어오는 거라면 이름 넣기
        else s.erase(name); // 퇴근하는 사람 이름 지우기
    }
   // for (auto i : s) cout << i << "\n";//역순이 아니라면
    //역순으로 출력
    vector<string> v(s.begin(), s.end());
    for (int i = v.size() - 1; i >= 0; i--)  cout << v[i] << "\n";
}


