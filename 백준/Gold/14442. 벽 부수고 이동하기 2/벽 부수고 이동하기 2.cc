#include <bits/stdc++.h>
#define X get<0>
#define Y get<1>
#define P get<2>

using namespace std;
string board[1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[1002][1002][11];
int result[1002][1002];
int N, M, K;
int main() {
    cin >> N >> M >> K;
    for(int i = 0; i<N; i++){
        cin >> board[i];
    }

    queue<tuple<int,int,int>> Q;
    vis[0][0][0] = 1;
    Q.push({0,0,0});
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int i = 0; i<4; i++){
            int nx = X(cur) + dx[i];
            int ny = Y(cur) + dy[i];
            if(nx < 0 || nx > N || ny < 0 || ny > M) continue;
            if(board[nx][ny] == '1'&& P(cur) < K && !vis[nx][ny][P(cur)+1]){
                vis[nx][ny][P(cur)+1] = 1;
                result[nx][ny] = result[X(cur)][Y(cur)] + 1;
                Q.push({nx, ny, P(cur)+1});
            }
            if(board[nx][ny] != '0' || vis[nx][ny][P(cur)]) continue;
            vis[nx][ny][P(cur)] = 1;
            result[nx][ny] = result[X(cur)][Y(cur)] + 1;
            Q.push({nx, ny, P(cur)});
            if(nx == N-1 && ny == M-1){
                cout << result[nx][ny]+1;
                return 0;
            }
        }
    }
    if(N == 1 && M == 1){
        cout << 1;
        return 0;
    }
    cout << -1;
    return 0;
}
