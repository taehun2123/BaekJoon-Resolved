#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int, int>
using namespace std;
int board[102][102];
bool vis[102][102]; //그룹화용 vis
int dist[102][102]; //다리 잇기용 dist
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N;

void groupIsland(){
    int index= 1;
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0 || vis[i][j]) continue;
            queue<pii> Q;
            vis[i][j] = 1;
            Q.push({i, j});
            while (!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                board[cur.X][cur.Y] = index;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (vis[nx][ny] || board[nx][ny] == 0) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            index++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> board[i][j];
        }
    }
    groupIsland();
    queue<pii> Q;
    for(int i = 0; i < N; i++)
        fill(dist[i], dist[i] + N, -1);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j] != 0){
                dist[i][j] = 0;
                Q.push({i,j});
            }
        }
    }
    int ans = INT_MAX;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(board[cur.X][cur.Y] == board[nx][ny]) continue;
            if(board[nx][ny] != 0){ // nx, ny가 다른 섬일 때 이은 다리 계산
                ans = min(ans, dist[cur.X][cur.Y]+dist[nx][ny]);
            }
            else { //바다일 경우
                board[nx][ny] = board[cur.X][cur.Y]; //인접한 바다를 육지로 만들고
                dist[nx][ny] = dist[cur.X][cur.Y] + 1; // dist 거리 추가
                Q.push({nx,ny});
            }
        }
    }
    cout << ans;
    return 0;
}
