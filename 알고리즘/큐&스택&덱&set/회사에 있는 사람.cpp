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
        if (log == "enter") s.insert(name); // ������ �Ŷ�� �̸� �ֱ�
        else s.erase(name); // ����ϴ� ��� �̸� �����
    }
   // for (auto i : s) cout << i << "\n";//������ �ƴ϶��
    //�������� ���
    vector<string> v(s.begin(), s.end());
    for (int i = v.size() - 1; i >= 0; i--)  cout << v[i] << "\n";
}


