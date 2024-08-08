#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1002];
vector<int> result;
int deg[1002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int no, u, v;
    for(int i = 0; i<m; i++){
        cin >> no; //보조 PD가 담당한 가수의 수
        if(no == 0) continue;
        cin >> u;
        while(--no){
            cin >> v;
            adj[u].push_back(v);
            deg[v]++;
            swap(u,v); //ex) 1 -> 4 /  4 -> 3
            //swap으로 v에 위치한 애를 u로 보냄
        }
    }

    queue<int> Q;
    for(int i = 1; i<=n; i++){
        if(deg[i] == 0) Q.push(i);
    }
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        result.push_back(cur);
        for(int nxt : adj[cur]){
            if(--deg[nxt] == 0) Q.push(nxt);
        }
    }
    if(result.size() != n)
        cout << 0 <<"\n";
    else
        for(auto x : result) cout << x << "\n";
    return 0;
}
