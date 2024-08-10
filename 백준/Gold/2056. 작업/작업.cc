#include <bits/stdc++.h>
using namespace std;

int n, tcnt;
vector<int> adj[10002];
int deg[10002];
int t[10002];
int result[10002]; // 각 작업의 완료 시간을 저장할 배열

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> tcnt;
        if (tcnt == 0) continue;
        while (tcnt--) {
            int priority;
            cin >> priority;
            adj[priority].push_back(i);
            deg[i]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            q.push(i);
            result[i] = t[i]; // 초기 작업 시간 설정
        }
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto nxt : adj[cur]) {
            result[nxt] = max(result[nxt], result[cur] + t[nxt]); // 최대 시간 계산
            if (--deg[nxt] == 0) q.push(nxt);
        }
    }

    // 모든 작업의 완료 시간 중에서 최대값을 찾는다
    int max_time = 0;
    for (int i = 1; i <= n; i++) {
        max_time = max(max_time, result[i]);
    }

    cout << max_time;

    return 0;
}
