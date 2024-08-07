#include <bits/stdc++.h>
using namespace std;
vector<int> adj[32002];
int deg[32002];
int n,m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }

    queue<int> Q;
    for(int i = 1; i<=n; i++) {
        if(deg[i] == 0) Q.push(i);
    }
    while (!Q.empty()){
        auto cur = Q.front(); Q.pop();
        cout << cur << " ";
        for(int nxt : adj[cur]){
            if(--deg[nxt] == 0) Q.push(nxt);
        }
    }
    return 0;
}
