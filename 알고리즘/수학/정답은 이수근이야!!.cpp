#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int check[] = {2,4,8,16,32,64};
int cnt1, cnt2;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int a, b, c;
    cin >> a >> b >>c;
    for (int i = -100; i <= 100; i++) {
        if (a * i * i + b * i + c == 0) {
            cnt1++; // ������
            for (int j = 0; j < 6; j++) {
                if (i == check[j]) cnt2++; //�̼���
            }
        }
    }
    if (cnt1 != 2) cout << "�Ѵ�Ʋ�ȱ�";
    else {
        if (cnt2 == 2) cout << "�̼���";
        else cout<<"������";
    }
}