#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, k, s, x, y;
int mp[201][201];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

struct Virus {
	int virus;
	int x;
	int y;
};
bool cmp(const Virus& v1, const Virus& v2) { // ����ü�� ���ſ��� ���α׷��� �ӵ��� ���߱⿡ �ּҷ� �޾ƿ�
	return v1.virus < v2.virus; // ���ı����� virus ��ȣ�� ���� ����
}
int main() {
	
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	vector<Virus> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
			if (mp[i][j] != 0) {
				v.push_back({ mp[i][j] ,i,j });
			}
		}
	}
	cin >> s >> x >> y;
	sort(v.begin(), v.end(), cmp); //���̷��� ��ȣ�� ���� ������ ����
	
	queue<Virus> q;
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		q.push(v[i]);
		cnt++;
	}
		
	for (int i = 0; i < s;i++) { // �ð� 
		for (int j = 0; j < cnt; j++) { 
			Virus tmp = q.front();
			q.pop();
			for (int l = 0; l < 4; l++) {
				int nx = dx[l] + tmp.x;
				int ny = dy[l] + tmp.y;
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (mp[nx][ny] != 0) continue;
				mp[nx][ny] = tmp.virus;
				q.push({ mp[nx][ny] , nx,ny });
			}
		}
		cnt = q.size();
	}
	cout << mp[x-1][y-1];
}