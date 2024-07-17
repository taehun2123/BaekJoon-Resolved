#include <bits/stdc++.h>
using namespace std;
string board[1002];
int dist[1002][1002][11][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1};
int N, M, K;
struct step{
    int X; //X
    int Y; //Y
    int W; //K
    int S; //sun(0) - night(1)
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for(int i = 0; i<N; i++) cin >> board[i];
    queue<step> Q;
    Q.push({0,0,0,0});
    dist[0][0][0][0] = 1;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        if(cur.X == N-1 && cur.Y == M-1){
            cout << dist[cur.X][cur.Y][cur.W][cur.S];
            return 0;
        }
        for(int dir = 0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(board[nx][ny] == '0'){ // 일반적인 BFS
                int nw = cur.W;
                int ns = 1-cur.S;
                if(dist[nx][ny][nw][ns] > 0) continue;
                dist[nx][ny][nw][ns] = dist[cur.X][cur.Y][cur.W][cur.S] + 1;
                Q.push({nx,ny,nw,ns});
            }
            else { // 벽일 때
                if(cur.W == K) continue; //K만큼 벽을 부쉈으면 continue;
                if(cur.S == 0){ // 낮이라면 벽 부수기
                    int nw = cur.W + 1;
                    int ns = 1-cur.S;
                    if(dist[nx][ny][nw][ns] > 0) continue;
                    dist[nx][ny][nw][ns] = dist[cur.X][cur.Y][cur.W][cur.S] + 1;
                    Q.push({nx,ny,nw,ns});
                }
                else { // 밤이라면 머무르기
                    int ns = 1-cur.S;
                    if(dist[cur.X][cur.Y][cur.W][ns] > 0) continue;
                    dist[cur.X][cur.Y][cur.W][ns] = dist[cur.X][cur.Y][cur.W][cur.S] + 1;
                    Q.push({cur.X,cur.Y,cur.W,ns});
                }
            }
        }
    }
    cout << -1;
    return 0;
}
