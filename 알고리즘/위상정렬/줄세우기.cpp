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
    st.push_back(u); //���̻� ������ ������ //������ ������ ���� ��
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
    while (st.size()) { // ������ ������ ���� ����ؾ���
        cout << st.back() << " ";
        st.pop_back();
    }
}