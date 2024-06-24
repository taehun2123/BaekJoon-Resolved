#include <bits/stdc++.h>
using namespace std;
int f, s, g, u, d;
int vis[1000005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> f >> s >> g >> u >> d;
    queue<int> Q;
    fill(vis+1, vis+f+1, -1);
    vis[s] = 0;
    Q.push(s);

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        if(cur == g){
            cout << vis[cur];
            return 0;
        }
        for(int move : {cur+u, cur-d}){
            if(move < 1 || move > f || vis[move] != -1) continue;
            vis[move] = vis[cur] + 1;
            Q.push(move);
        }
    }
    cout << "use the stairs";

    return 0;
}
