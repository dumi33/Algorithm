#include<iostream>
#include<string>
using namespace std;
int N;
string str = "____";
void func(int n) {
    if (n == 0) {
        for (int i = N - n; i > 0; i--) cout << str;
        cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
        for (int i = N - n; i > 0; i--) cout << str;
        cout << "��� �亯�Ͽ���.\n";
        return;
    }
    for (int i = N - n; i > 0; i--) cout << str;
    cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
    for (int i = N - n; i > 0; i--) cout << str;
    cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
    for (int i = N - n; i > 0; i--) cout << str;
    cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
    for (int i = N - n + 1; i > 0; i--) cout << str;
    cout << "\"����Լ��� ������?\"\n";
    func(n - 1);
    for (int i = N - n; i > 0; i--) cout << str;
    cout << "��� �亯�Ͽ���.\n";
}
int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    cin >> N;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    cout << "\"����Լ��� ������?\"\n";
    func(N);
}