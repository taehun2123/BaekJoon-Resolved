#include <bits/stdc++.h>
using namespace std;
string board[105];
int vis[105][105];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<n; i++)
        cin >> board[i];
    queue<pair<int,int>> Q;
    Q.push({0,0});
    vis[0][0] = 1;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int i = 0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] != '1' || vis[nx][ny] > 0) continue;
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }
    cout << vis[n-1][m-1];
    return 0;
}
