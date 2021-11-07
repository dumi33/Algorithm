#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m, k, x;

vector<int> graph[300001]; //���� �迭
vector<int> dist(300001, -1); // -1�� �ʱ�ȭ�� 300001 ���� ���Ҹ� ���� ���� // ���������κ����� �Ÿ� ����


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k >> x;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b); // ���ó��� �̾����� ���� 
	}
	dist[x] = 0; //�������� dist�� 0�̴�.
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int j = 0; j < graph[now].size(); j++) {
			int next = graph[now][j];
			if (dist[next] == -1) { //ù�湮
				dist[next] = dist[now] + 1;
				q.push(next);
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] == k) {
			cout << i << "\n";
			cnt++;
		}
	}
	if (cnt == 0) cout << -1;
}