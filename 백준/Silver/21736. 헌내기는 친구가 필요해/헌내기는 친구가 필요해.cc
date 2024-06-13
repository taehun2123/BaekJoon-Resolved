#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

string board[601];
bool vis[601][601];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        cin >> board[i];
    }
    queue<pair<int,int>> Q;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(board[i][j] == 'I'){
                Q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int i =0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == 'X' || vis[nx][ny]) continue;
            if(board[nx][ny] == 'P') cnt++;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
    if(cnt == 0) cout << "TT";
    else cout << cnt;
    return 0;
}
