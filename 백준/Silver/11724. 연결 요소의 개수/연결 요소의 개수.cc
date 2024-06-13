#include <bits/stdc++.h>
using namespace std;
vector<int> board[1002];
bool vis[1002];
int n, m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        board[u].push_back(v);
        board[v].push_back(u);
    }
    int cnt = 0;
    queue<int> Q;
    for(int i = 1; i<=n; ++i){
        if(vis[i]) continue;
        Q.push(i);
        vis[i] = true;
        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            for(auto j : board[cur]){
                if(vis[j]) continue;
                Q.push(j);
                vis[j] = true;
            }
        }
        cnt++;
    }
    cout << cnt;
    return 0;
}
