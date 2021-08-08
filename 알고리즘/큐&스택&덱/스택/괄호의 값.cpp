#include<iostream>
#include<stack>
using namespace std;

int tmp = 1, ans = 0;
bool isok = true;
string str;
stack<char> stk;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin ����ӵ� ���
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            tmp *= 2;
            stk.push('(');
        }
        else if (str[i] == '[') {
            tmp *= 3;
            stk.push('[');
        }
        else if (str[i] == ')' && (stk.empty() || stk.top() != '(')) {
            isok = false;
                break;
        }
        else if (str[i] == ']' && (stk.empty() || stk.top() != '[')) {
            isok = false;
                break;
        }
        else if (str[i] == ')') {
            if (str[i - 1] == '(') ans += tmp;  //�ٷ� ���� ���ڰ� ¦���ϰ�츸
                stk.pop();
                tmp /= 2;
        }
        else if (str[i] == ']') {
            if (str[i - 1] == '[') ans += tmp;  //�ٷ� ���� ���ڰ� ¦���ϰ�츸
                stk.pop();
                tmp /= 3;
        }
    }

    if (stk.empty() == false || isok == false) cout << 0;
    else cout << ans;
}



