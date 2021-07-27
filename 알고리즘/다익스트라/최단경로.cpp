#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> PI;

int v, e, start,dist[20001],visit[20001];
vector<vector<pair<int, int>>> V;
priority_queue<PI,vector<PI>,greater<PI> > q; // firtst -> w, second -> v
//작은놈부터 나오도록
//priority_queue<PI > q; 와 같은데 최솟값먼저 나오게 하기위해서

int main() {

    cin >> v >> e >> start;
    V.resize(v + 1);
    fill(dist, dist + v + 1, 2e9);

    for (int i = 0, p1, p2, p3; i< e; i++) {
        cin >> p1 >> p2 >> p3; // u v w
        V[p1].push_back({ p2,p3 }); 
    } 
    dist[start] = 0;
    q.push({ 0,start }); /// start는 가중치가 0이므로
    while (!q.empty()) {
        int cur; //현재 정점의 상태
        do {
            cur = q.top().second; // first에는 가중치가있으므로
            q.pop();
        } while (!q.empty() && visit[cur]);
        if (visit[cur]) break;
        visit[cur] = true;
        for (auto& i : V[cur]) {
            int next = i.first; //정점
            int ndist = i.second; // 가중치
            if (dist[next] > dist[cur] + ndist) {
                dist[next] = dist[cur] + ndist; //업데이트
                q.push({ dist[next],next });
            }
        }
    }
    for (int i = 1; i <= v; i++) {
        if (dist[i] == 2e9) cout << "INF" << "\n";
        else cout << dist[i] << "\n";
    }
}