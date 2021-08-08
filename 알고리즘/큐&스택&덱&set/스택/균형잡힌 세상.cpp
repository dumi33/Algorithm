#include<iostream>
#include<string> // getline �̿�
#include<stack>
using namespace std;

int k;
string input;
bool res;
stack <int> stk;

int main() {
    while (1) {
        res = true;
        getline(cin, input); // �ѹ��徿
        if (input == ".") break; // �� "�ϳ�"�� ������
        for (char c : input) {
            if (c == '(') stk.push('(');
            else if (c == '[') stk.push('[');
            else if (c == ')') {
                if (stk.empty()) {
                    res = false;
                    break;
                }
                else { //������� �ʾ�
                    if (stk.top() == '(') { //���� �ߵɶ�
                        stk.pop();
                    }
                    else {
                        res = false;
                        break;
                    }

                }
            }
            else if (c == ']') {
                if (stk.empty()) {
                    res = false;
                    break;
                }
                else { //������� �ʾ�
                    if (stk.top() == '[') { //���� �ߵɶ�
                        stk.pop();
                    }
                    else {
                        res = false;
                        break;
                    }

                }
            }
        }
        while (!stk.empty()) { // Ȥ�ö� �����ִٸ�!
            res = false;
            stk.pop(); // ������ ������ ���ؼ�
        }
        cout << (res ? "yes" : "no") << "\n";
    }
}