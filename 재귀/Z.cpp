#include<iostream>
using namespace std;
int func(int n, int r, int c) {//r은 행 c는 열
    if (n == 0) return 0;
    int half = 1 << (n - 1);//2^(n-1)을 의미한다.즉 한변/2 이므로 길이의 반
    if (r < half && c < half) return func(n - 1, r, c); //첫번째 네모
    if (r < half && c >= half) return half * half + func(n - 1, r, c - half); //두번째 네모 //열이 반보다 클때 //재귀는 반보다 큰값을 줄여서 다시 부른다.
    if (r >= half && c < half) return 2 * half * half + func(n - 1, r - half, c); //세번째 네모
    return 3 * half * half + func(n - 1, r - half, c - half); //네번째 네모
}
int main() {
    int n, r, c;
    cin >> n >> r >> c;
    cout << func(n, r, c);
}