#include<iostream>
#include<vector>
using namespace std;

vector<int> v;

int n, m, cnt;
int ptr1;

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp; 
		v.push_back(tmp);
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			ptr1 += v[j];
			if (ptr1 == m) {
				cnt++;
				break;
			}
		}
		ptr1 = 0;
	}
	cout<< cnt;
}