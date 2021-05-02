#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> adj[101];
int com, m;

bool vis[101];
int dfs(int n) {
    int ans = 1; //아무것도 연결되어있지 않아도 1을 반환해야하기때문에
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

    cout << dfs(1) - 1; // 1번째 컴퓨터도 1을 가진다 그러나 첫번째 컴퓨터는 count 하지않아서 -1을 해준다.
}