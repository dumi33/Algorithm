#include<iostream>
#include<deque>
using namespace std;
deque<int> v;
int main() {
    int n;
    cin >> n;
    for (int i = n; i > 0; i--) {
        v.push_back(i);
    }
    while (v.size() != 1) {
        v.pop_back();
        int cur = v.back();
        v.pop_back();
        v.push_front(cur);
    }
    cout << v[0];
}
  
