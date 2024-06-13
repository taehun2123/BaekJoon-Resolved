#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int board[1002][1002];
int dist[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    queue<pair<int,int>> Q;
    fill(dist[0], dist[1001], -1);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> board[i][j];
            if(board[i][j] == 1)
                dist[i][j] = 0;
            if(board[i][j] == 2){
                dist[i][j] = 1;
                Q.push({i,j});
            }
        }
    }
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int i = 0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx > 1000 || ny < 0 || ny > 1000) continue;
            if(board[nx][ny] == 0 || dist[nx][ny] != 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    for(int i = 0; i<n;i++){
        for(int j = 0; j<m; j++){
            if(dist[i][j] == -1)
                dist[i][j] += 2;
            cout << dist[i][j]-1 << " ";
        }
        cout << "\n";
    }
    return 0;
}
