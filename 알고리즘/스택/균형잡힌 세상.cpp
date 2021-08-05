#include<iostream>
#include<string> // getline 이용
#include<stack>
using namespace std;

int k;
string input;
bool res;
stack <int> stk;

int main() {
    while (1) {
        res = true;
        getline(cin, input); // 한문장씩
        if (input == ".") break; // 점 "하나"만 들어오면
        for (char c : input) {
            if (c == '(') stk.push('(');
            else if (c == '[') stk.push('[');
            else if (c == ')') {
                if (stk.empty()) {
                    res = false;
                    break;
                }
                else { //비어있지 않아
                    if (stk.top() == '(') { //연결 잘될때
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
                else { //비어있지 않아
                    if (stk.top() == '[') { //연결 잘될때
                        stk.pop();
                    }
                    else {
                        res = false;
                        break;
                    }

                }
            }
        }
        while (!stk.empty()) { // 혹시라도 남아있다면!
            res = false;
            stk.pop(); // 스택의 재사용을 위해서
        }
        cout << (res ? "yes" : "no") << "\n";
    }
}