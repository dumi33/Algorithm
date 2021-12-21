#include<iostream>
using namespace std;
int main() {
    int day = 1;
    int a, b, v;
    cin >> a >> b >> v;
    day += (v - a) / (a - b);
    if ((v - a) % (a - b) == 0) cout << day;
    else cout << day+1;

}