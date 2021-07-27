#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int v, e, s, st;
vector<int> adj[1001];
bool vis[1001];
void dfs(int cur) {
    cout << cur << ' ';
    for (int i = 0; i < adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (vis[nxt]) continue; // 이미 방문 했으면 pass
        vis[nxt] = true;
        dfs(nxt);
    }
}
void bfs() {
    queue<int> q;
    q.push(st);
    vis[st] = true; //갔다는 표시
    while (!q.empty()) {
        int cur = q.front();
        cout << cur << ' ';
        q.pop();
        for (int i = 0; i < adj[cur].size(); i++) {
            int nxt = adj[cur][i];
            if (vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }

}
int main() {
    cin >> v >> e >> st;
    while (e--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= v; i++) { //노드가 1부터 있어서
        sort(adj[i].begin(), adj[i].end());
    }
    vis[st] = true;
    dfs(st);
    cout << "\n";
    fill(vis, vis + v + 1, 0);
    bfs();
}