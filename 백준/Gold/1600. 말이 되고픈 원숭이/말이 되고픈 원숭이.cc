#include <bits/stdc++.h>
using namespace std;
int K, W, H, ans = INT_MAX;
int board[205][205];
int dist[205][205][35];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int hdx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int hdy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
struct step {
    int X, Y, HW;
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> K >> W >> H;
    for(int i = 0; i<H; i++){
        for(int j = 0; j<W; j++){
            cin >> board[i][j];
            for(int k=0; k<=K; k++){
                dist[i][j][k] = -1;
            }
        }
    }
    if(H==1 && W==1){
        cout<<0;
        return 0;
    }

    queue<step> Q;
    Q.push({0,0,0});
    dist[0][0][0] = 0;

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        if(cur.HW > K) continue;
        for(int dir = 0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if( nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(board[nx][ny] != 0) continue;
            if(dist[nx][ny][cur.HW] != -1){
                dist[nx][ny][cur.HW] = min(dist[nx][ny][cur.HW], dist[cur.X][cur.Y][cur.HW]+1);
            } else {
                dist[nx][ny][cur.HW] = dist[cur.X][cur.Y][cur.HW] + 1;
                Q.push({nx, ny, cur.HW});
            }
        }
        for(int dir = 0; dir<8; dir++){
            int nx = cur.X + hdx[dir];
            int ny = cur.Y + hdy[dir];
            if( nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(board[nx][ny] != 0) continue;
            if(dist[nx][ny][cur.HW+1] != -1){
                dist[nx][ny][cur.HW+1] = min(dist[nx][ny][cur.HW+1], dist[cur.X][cur.Y][cur.HW]+1);
            } else {
                dist[nx][ny][cur.HW+1] = dist[cur.X][cur.Y][cur.HW] + 1;
                Q.push({nx, ny, cur.HW+1});
            }
        }
    }

    for(int k = 0; k<=K; k++)
        if(dist[H-1][W-1][k] != -1)
            ans = min(ans, dist[H-1][W-1][k]);
    if(ans == INT_MAX) cout << -1;
    else cout << ans;
    return 0;
}
