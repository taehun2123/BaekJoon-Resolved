#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int N, M, V;
bool vis[1002];
vector<int> adj[1002];

void DFS(int x){
    cout << x << " ";
    vis[x] = true;
    sort(adj[x].begin(), adj[x].end());
    for(int y : adj[x])
        if(!vis[y]) DFS(y);
}
void BFS(int st){
    queue<int> Q;
    Q.push(st);
    vis[st] = true;
    while(!Q.empty()){
        int x = Q.front(); Q.pop();
        cout << x << " ";
        for(int i = 0; i<adj[x].size(); i++){
            sort(adj[x].begin(), adj[x].end());
            int y = adj[x][i];
            if(!vis[y]){
                Q.push(y);
                vis[y] = true;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> V;
    for(int i = 1; i<=M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(V);
    cout << "\n";
    memset(vis, 0, sizeof(vis));
    BFS(V);
    return 0;
}
