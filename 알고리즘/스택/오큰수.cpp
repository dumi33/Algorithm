

#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> v;
stack <int> s;
int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        v.push_back(num);
    }

    vector<int> ans(v.size(), -1);// v의 사이즈로 -1로 초기화하여 ans라는 벡터를 생성

    for (int i = 0; i < n; i++) {
        while (!s.empty() && v[s.top()] < v[i]) {//v[i]가 무조건 오른쪽
            ans[s.top()] =v[i];
            s.pop();
        }
        s.push(i); // 인덱스를 넣는다.
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}
  
