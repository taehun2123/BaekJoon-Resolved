#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int board[102][102];
int vis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int m, n, k, cnt;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> k;
    while(k--){ // 벽 세우기 작업
        int spx, spy, epx, epy;
        cin >> spx >> spy >> epx >> epy;
        for(int j = spy; j<epy; j++)
            for(int l = spx; l<epx; l++)
                board[j][l] = 1;
    }
    vector<int> arrNub;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(board[i][j] == 1 || vis[i][j] == 1) continue;
            queue<pair<int,int>> Q;
            vis[i][j] = 1;
            int nub = 1;
            cnt++;
            Q.push({i, j});
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int dir = 0; dir<4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if(board[nx][ny] == 1 || vis[nx][ny] == 1) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                    nub++;
                }
            }
            arrNub.push_back(nub);
        }
    }
    cout << cnt <<"\n";
    sort(arrNub.begin(), arrNub.end());
    for(auto i:arrNub){
        cout << i << " ";
    }

    return 0;
}
