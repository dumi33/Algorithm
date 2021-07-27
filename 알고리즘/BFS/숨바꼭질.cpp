#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define x first 
#define y second
int dist[100002];
int main() { //1차원 BFS
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    int n, k;
    cin >> n >> k; //n은 수빈, K는 동생
    fill(dist, dist + 100001, -1); //-1로 초기화
    dist[n] = 0; //수빈이 자리는 0
    queue<int> Q;
    Q.push(n);
    while (dist[k] == -1) { //동생자리가 비어있을동안
        int cur = Q. front();
        Q.pop();
        for (int next : {cur - 1, cur + 1, 2 * cur}) {
            if (next < 0 || next > 100000) continue; //범위를 나가면 pass
            if (dist[next] != -1) continue; //이미 왔었으면 pass
            dist[next] = dist[cur] + 1;
            Q.push(next);
        }
    }
    cout << dist[k];
}