#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int vis[305][305];
int dx[8] = {1, -1, -2, -2, 1, -1, 2, 2};
int dy[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int T;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        int n, x, y, gx,gy;
        cin >> n;
        cin >> x >> y >> gx >> gy;
        queue<pair<int,int>> Q;
        if(x == gx && y == gy){
            cout << 0 << "\n";
            continue;
        }
        for(int i = 0; i<n; i++)
            fill(vis[i], vis[i]+n, -1);
        vis[x][y] = 0;
        Q.push({x, y});
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(int i = 0; i<8; i++){
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(vis[nx][ny] >= 0) continue;
                vis[nx][ny] = vis[cur.X][cur.Y]+1;
                Q.push({nx, ny});
            }
        }
        cout << vis[gx][gy] << "\n";
    }
}
