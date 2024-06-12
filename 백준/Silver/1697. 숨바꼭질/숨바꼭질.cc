#include <bits/stdc++.h>
using namespace std;
int n, k;
int vis[100002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    fill(vis, vis+100001, -1);
    queue<int> Q;
    vis[n] = 0;
    Q.push(n);
    while(vis[k] == -1){
        int cur = Q.front(); Q.pop();
        for(int dot : {cur-1, cur+1, cur*2}){
            if(dot < 0 || dot > 100000) continue;
            if(vis[dot] != -1) continue;
            vis[dot] = vis[cur] + 1;
            Q.push(dot);
        }
    }
    cout << vis[k];
    return 0;
}
