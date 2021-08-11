#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > g;
vector<int> st, vis;
void dfs(int u) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v]) dfs(v);
    }
    st.push_back(u); //더이상 간선이 없을때 //위상이 낮은것 먼저 들어감
}
int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }
    while (st.size()) { // 위상이 높은것 부터 출력해야함
        cout << st.back() << " ";
        st.pop_back();
    }
}