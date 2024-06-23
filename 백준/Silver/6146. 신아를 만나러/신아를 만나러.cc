#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int board[1001][1001];
int dist[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int x, y, n;
queue<pair<int,int>> Q;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> y >> n;
    for(int i = 0; i<n; i++){
        int x, y;
        cin >> x >> y;
        board[x + 500][y + 500] = 1;
    }
    Q.push({500, 500});
    dist[500][500] = 1;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int i = 0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || ny < 0 || nx > 1000 || ny > 1000) continue;
            if(board[nx][ny] == 1 || dist[nx][ny] > 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    cout << dist[x+500][y+500]-1;
    return 0;
}
