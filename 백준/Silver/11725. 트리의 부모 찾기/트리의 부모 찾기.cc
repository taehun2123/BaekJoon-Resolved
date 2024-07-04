#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> arr[100002];
bool vis[100002];
int ans[100002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    queue<int> Q;
    Q.push(1);
    vis[1] = true;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int i = 0; i<arr[cur].size(); i++){
            int child = arr[cur][i];
            if(!vis[child]){
                ans[child] = cur;
                vis[child] = 1;
                Q.push(child);
            }
        }
    }

    for(int i = 2; i<=n; i++){
        cout << ans[i] << "\n";
    }


    return 0;
}
