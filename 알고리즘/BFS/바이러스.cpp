#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int> > v;
int ans = 0;
int vis[101];
int bfs() {
    queue<int> q;
    vis[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i : v[cur]) {
            if (!vis[i]) {
                vis[i] = 1;
                ans++;
                q.push(i);
            }
            else continue;
        }
    }
    return ans;
}
int main() {
    int n, m;
    cin >> n >> m;
    v.resize(n + 1); // �ڸ��� �־�߸� v[i].push_back(3); �̷��� ����
    for (int i = 0,x,y; i < m; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cout << bfs();
    
}