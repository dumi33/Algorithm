#include<iostream>
using namespace std;
int func(int n, int r, int c) {//r�� �� c�� ��
    if (n == 0) return 0;
    int half = 1 << (n - 1);//2^(n-1)�� �ǹ��Ѵ�.�� �Ѻ�/2 �̹Ƿ� ������ ��
    if (r < half && c < half) return func(n - 1, r, c); //ù��° �׸�
    if (r < half && c >= half) return half * half + func(n - 1, r, c - half); //�ι�° �׸� //���� �ݺ��� Ŭ�� //��ʹ� �ݺ��� ū���� �ٿ��� �ٽ� �θ���.
    if (r >= half && c < half) return 2 * half * half + func(n - 1, r - half, c); //����° �׸�
    return 3 * half * half + func(n - 1, r - half, c - half); //�׹�° �׸�
}
int main() {
    int n, r, c;
    cin >> n >> r >> c;
    cout << func(n, r, c);
}