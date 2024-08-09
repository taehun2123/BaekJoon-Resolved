#include <bits/stdc++.h>
using namespace std;
vector<int> adj[32002];
int deg[32002];
int cnt[32002];
int n,m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    fill(cnt, cnt+n+1, 1);
    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }

    queue<pair<int,int>> Q;
    for(int i = 1; i<=n; i++) {
        if(deg[i] == 0) Q.push({i,1});
    }
    while (!Q.empty()){
        auto cur = Q.front(); Q.pop();
        cnt[cur.first] = cur.second;
        for(int nxt : adj[cur.first]){
            if(--deg[nxt] == 0) Q.push({nxt, cur.second+1});
        }
    }

    for(int i = 1; i<=n; i++){
        cout << cnt[i] <<" ";
    }
    return 0;
}
