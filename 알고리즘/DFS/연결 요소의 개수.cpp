#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > adj;
int vis[1001];
void dfs(int i) {
    vis[i] = 1;
    for (auto next : adj[i]) {
        if (!vis[next]) {
            dfs(next);
        }
    }
}
int main() {
    int n, m; cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;
}