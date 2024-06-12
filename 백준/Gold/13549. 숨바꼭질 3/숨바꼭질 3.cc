#include <bits/stdc++.h>
using namespace std;
int n, k;
int vis[100002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    fill(vis, vis+100002, -1);
    queue<int> Q;

    vis[n] = 0;
    Q.push(n);

    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        if(cur == k){
            cout << vis[cur];
            return 0;
        }
        // *2의 경우를 먼저 처리하여 큐의 맨 앞에 넣는다.
        if (cur * 2 <= 100000 && vis[cur * 2] == -1) {
            vis[cur * 2] = vis[cur];
            Q.push(cur * 2);
        }

        for(int dot : {cur-1, cur+1}){
            if(dot < 0 || dot > 100000) continue;
            if(vis[dot] != -1) continue;
            vis[dot] = vis[cur] + 1;
            Q.push(dot);
        }
    }
    return 0;
}
