#include <bits/stdc++.h>
using namespace std;

int test,n,k,w;
vector<int> adj[100002];
int deg[100002];
int t[100002];
int result[100002]; // 각 작업의 완료 시간을 저장할 배열

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while(test--){
    cin >> n >> k;
    for(int i = 0; i<=n; i++) fill(adj[i].begin(), adj[i].end(), 0);
    fill(deg, deg+100002, 0);
    fill(t, t+100002, 0);
    fill(result, result+100002, 0);
    for(int i = 1; i <= n; i++) cin >> t[i];
    for(int i = 1; i <= k; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }
    cin >> w;

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

    cout << result[w] << "\n";
    }

    return 0;
}
