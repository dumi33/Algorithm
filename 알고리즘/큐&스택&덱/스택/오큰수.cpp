

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

    vector<int> ans(v.size(), -1);// v�� ������� -1�� �ʱ�ȭ�Ͽ� ans��� ���͸� ����

    for (int i = 0; i < n; i++) {
        while (!s.empty() && v[s.top()] < v[i]) {//v[i]�� ������ ������
            ans[s.top()] =v[i];
            s.pop();
        }
        s.push(i); // �ε����� �ִ´�.
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}
  
