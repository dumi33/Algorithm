#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int n, int m) {
    
    if (m == 0) return n;
    return gcd(m, n % m);
}
int lcd(int n, int m, int gcd) {
    return n * m / gcd;
}
int main() {
    int n, m;
    cin >> n >> m;
    if (m > n) swap(n, m);
    int gcd1 = gcd(n, m);
    int lcd1 = lcd(n, m, gcd1);
    cout << gcd1 << "\n" << lcd1;
}