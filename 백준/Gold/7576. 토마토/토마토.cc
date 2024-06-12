#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int board[1005][1005];
bool vis[1005][1005];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
queue<pair<int,int>> Q;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> board[i][j];
            if(board[i][j] == -1)
                vis[i][j] = true;
            if(board[i][j] == 1){
                Q.push({i, j});
                vis[i][j] = true;
            }
        }
    }
    int ans = 0;
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        ans = max(ans, board[cur.X][cur.Y]);
        for(int i = 0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny]) continue;
            vis[nx][ny] = true;
            board[nx][ny] = board[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(!vis[i][j]){
                cout << -1;
                return 0;
            }
        }
    }
    cout << ans-1;
    return 0;
}
