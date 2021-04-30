#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define x first 
#define y second
int dist[100002];
int main() { //1���� BFS
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    int n, k;
    cin >> n >> k; //n�� ����, K�� ����
    fill(dist, dist + 100001, -1); //-1�� �ʱ�ȭ
    dist[n] = 0; //������ �ڸ��� 0
    queue<int> Q;
    Q.push(n);
    while (dist[k] == -1) { //�����ڸ��� �����������
        int cur = Q. front();
        Q.pop();
        for (int next : {cur - 1, cur + 1, 2 * cur}) {
            if (next < 0 || next > 100000) continue; //������ ������ pass
            if (dist[next] != -1) continue; //�̹� �Ծ����� pass
            dist[next] = dist[cur] + 1;
            Q.push(next);
        }
    }
    cout << dist[k];
}