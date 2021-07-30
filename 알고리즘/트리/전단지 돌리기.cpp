#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, S, D;
int x, y;
int ans;
vector<int> adj[100001];
int d[100001];
void dfs(int v, int par) {
    if (v != S && adj[v].size() == 1) d[v] = 1;  //리프노드일때
    else {
        for (auto i : adj[v]) {
            if (i == par) continue;
            dfs(i, v);
            d[v] = max(d[v], d[i] + 1); // 자식보다 +1
        }
    }
    if (v != S && d[v] > D) ans += 2;
}
int main() {
    cin >> N >> S >> D;
    for (int i = 0; i < N - 1; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(S, 0);
    cout << ans;
}