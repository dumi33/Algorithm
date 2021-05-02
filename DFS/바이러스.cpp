#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> adj[101];
int com, m;

bool vis[101];
int dfs(int n) {
    int ans = 1; //�ƹ��͵� ����Ǿ����� �ʾƵ� 1�� ��ȯ�ؾ��ϱ⶧����
    vis[n] = 1;
    for (int i : adj[n]) {
        if (vis[i] != 1) ans += dfs(i);
    }
    return ans;
}

int main() {

    cin >> com >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << dfs(1) - 1; // 1��° ��ǻ�͵� 1�� ������ �׷��� ù��° ��ǻ�ʹ� count �����ʾƼ� -1�� ���ش�.
}