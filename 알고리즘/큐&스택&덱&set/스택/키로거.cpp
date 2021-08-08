#include<iostream>
#include<stack>
#include<algorithm> // reverse�̿��ϱ�����
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int test_case; cin >> test_case;
    while (test_case--) {
        string str; cin >> str;

        stack<char> result;// ���
        stack<char> temp; // ȭ��ǥ ����

        for (char c : str) {
            if (c == '<') { // ���� ȭ��ǥ
                if (!result.empty()) {
                    temp.push(result.top());
                    result.pop();
                }

            }
            else if (c == '>') {
                if (!temp.empty()) {
                    result.push(temp.top());
                    temp.pop();
                }
            }
            else if (c == '-') {
                if (!result.empty()) {
                    result.pop();
                }
            }
            else { // �ƹ��͵� �ƴҰ��
                result.push(c);
            }
        }
        while (!temp.empty()) {
            result.push(temp.top());
            temp.pop();
        }
        string ans;
        while (!result.empty()) {
            ans += result.top();
            result.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }

}


