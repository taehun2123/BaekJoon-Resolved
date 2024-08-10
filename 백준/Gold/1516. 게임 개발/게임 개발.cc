#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[100002];
int deg[100002];
int t[100002];
int result[100002]; // 각 작업의 완료 시간을 저장할 배열

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> t[i];
        while(true) {
            int priority;
            cin >> priority;
            if(priority == -1) break;
            adj[priority].push_back(i);
            deg[i]++;
        }
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 0) {
            q.push(i);
            result[i] = t[i]; // 초기 작업 시간 설정
        }
    }

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto nxt : adj[cur]) {
            result[nxt] = max(result[nxt], result[cur] + t[nxt]); // 최대 시간 계산
            if(--deg[nxt] == 0) q.push(nxt);
        }
    }

    for(int i = 1; i <= n; i++) cout << result[i] << "\n";


    return 0;
}
