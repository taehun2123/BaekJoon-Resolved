#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int board[52][52];
bool vis[52][52];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int T, M, N, K;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> M >> N >> K;
        fill(board[0], board[51], 0);
        fill(vis[0], vis[51], 0);
        for(int i = 0; i<K; i++){
            int u, v;
            cin >> u >> v;
            board[v][u] = 1;
        }
        int cnt = 0;
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                if(board[i][j] == 0 || vis[i][j]) continue;
                cnt++;
                queue<pair<int,int>> Q;
                vis[i][j] = 1;
                Q.push({i,j});
                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int dir = 0; dir<4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if(board[nx][ny] != 1 || vis[nx][ny]) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
