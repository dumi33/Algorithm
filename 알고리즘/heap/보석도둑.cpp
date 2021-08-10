#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n, k, ans;
pair<int, int> jew[300001];
int bag[300001];
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> jew[i].first >> jew[i].second;
    }
    for (int i = 0; i < k; i++) cin >> bag[i];

    sort(jew, jew + n);
    sort(bag, bag + k);

    for (int i = 0; i < k; i++) { // 가방의 개수만큼
        int idx = 0;
        while (idx < n && jew[idx].first <= bag[i]) {
            pq.push(jew[idx++].second); // idx를 넣어주고 ++해준다.
        }
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
}
