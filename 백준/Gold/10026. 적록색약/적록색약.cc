#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

string board[101];
bool vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> board[i];
    }
    queue<pair<int,int>> Q;
    int noRgcnt = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(vis[i][j]) continue;
            Q.push({i, j});
            vis[i][j] = 1;
            noRgcnt++;
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int i =0; i<4; i++){
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(board[nx][ny] != board[cur.X][cur.Y] || vis[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(board[i][j] == 'G'){
                board[i][j] = 'R';
            }
        }
    }
    fill(vis[0], vis[100], false);
    int rgCnt = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(vis[i][j]) continue;
            Q.push({i, j});
            vis[i][j] = 1;
            rgCnt++;
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int i =0; i<4; i++){
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(board[nx][ny] != board[cur.X][cur.Y] || vis[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    }

    cout << noRgcnt << " " << rgCnt;
    return 0;
}
