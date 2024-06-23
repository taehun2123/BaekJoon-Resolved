#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
string board[1005];
int dist1[1005][1005];
int dist2[1005][1005];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int w, h;
        cin >> w >> h;
        bool flag = false;
        queue<pair<int,int>> Q1; //불의 퍼짐
        queue<pair<int,int>> Q2; //상근이의 니게로
        for(int i = 0; i<h; i++){
            fill(dist1[i], dist1[i]+w, -1);
            fill(dist2[i], dist2[i]+w, -1);
        }

        for(int i = 0; i<h; i++){
            cin >> board[i];
            for(int j = 0; j<w; j++){
                if(board[i][j] == '*'){
                    Q1.push({i, j});
                    dist1[i][j]++;
                }
                if(board[i][j] == '@'){
                    Q2.push({i,j});
                    dist2[i][j]++;
                }
            }
        }
        while(!Q1.empty()){
            auto cur = Q1.front(); Q1.pop();
            for(int i = 0; i<4; i++){
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
                dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
                Q1.push({nx, ny});
            }
        }
        while(!Q2.empty()){
            if(flag) break;
            auto cur = Q2.front(); Q2.pop();
            for(int i = 0; i<4; i++){
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w){
                    cout << dist2[cur.X][cur.Y]+1 << "\n";
                    flag = true;
                    break;
                }
                if(dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
                if(dist1[nx][ny] >= 0 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue;
                dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
                Q2.push({nx, ny});
            }
        }
        if(flag) continue;
        cout << "IMPOSSIBLE" << "\n";
    }
    return 0;
}
