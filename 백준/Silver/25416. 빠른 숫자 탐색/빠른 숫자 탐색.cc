#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int board[10][10];
int dist[10][10];
int N = 5;
int stx, sty;
int cnt;
queue<pair<int, int>> Q;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < N; i++)
        fill(dist[i], dist[i] + N, -1);
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> board[i][j];
        }
    }
    cin >> stx >> sty;


    Q.push({stx, sty});
    dist[stx][sty] = 0;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        cnt++;
        for(int ii = 0; ii<4; ii++) {
            int ndx = cur.first + dx[ii];
            int ndy = cur.second + dy[ii];
            if(ndx < 0 || ndx >= N || ndy < 0 || ndy >= N) continue;
            if(board[ndx][ndy] == -1 || dist[ndx][ndy] != -1) continue;
            if(board[ndx][ndy] == 1) {
                cout << dist[cur.first][cur.second] + 1;
                return 0;
            }
            dist[ndx][ndy] = dist[cur.first][cur.second] + 1;
            Q.push({ndx, ndy});
        }
    }

    cout << -1;

    return 0;
}
