#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<vector<int>> adj;
int vis[20001];

void dfs(int cur, int i) {
    vis[cur] = i; // 색깔을 입력
    for (auto k : adj[cur]) {
        if (vis[k] == 0) {
            dfs(k, 3 - i);
        }
    }
}
int main() {
    int tc; cin >> tc;
    while (tc--) {
        int v, e; cin >> v >> e;
        memset(vis, 0, sizeof(vis));
        adj.resize(v + 1);
        for (int i = 1; i <= v; i++) {
            adj[i].clear();
        }
        for (int i = 0, a, b; i < e; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int i = 1; i <= v; i++) {
            if (vis[i] == 0) {
                dfs(i, 1);
            }
        }
        bool isok = true;
        for (int i = 1; i <= v; i++) {
            if (adj[i].empty()) continue;
            for (int j : adj[i]) {
                if (vis[i] == vis[j]) isok = false; //인접한 노드가 같은 색이라면
            }
        }
        isok ? cout << "YES\n" : cout << "NO\n";
    }
}