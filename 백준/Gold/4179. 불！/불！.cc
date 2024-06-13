#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
string board[1002];
int dist1[1002][1002];
int dist2[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int r, c;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    queue<pair<int,int>> Q1;
    queue<pair<int,int>> Q2;
    for(int i = 0; i<r; i++){
        fill(dist1[i], dist1[i]+c, -1);
        fill(dist2[i], dist2[i]+c, -1);
    }
    for(int i = 0; i<r; i++){
        cin >> board[i];
        for(int j = 0; j<c; j++){
            if(board[i][j] == 'F'){
                dist1[i][j] = 0;
                Q1.push({i,j});
            }
            if(board[i][j] == 'J'){
                dist2[i][j] = 0;
                Q2.push({i, j});
            }
        }
    }
    //불부터 계산할랭
    while(!Q1.empty()){
        pair<int,int> cur = Q1.front(); Q1.pop();
        for(int i = 0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            Q1.push({nx, ny});
        }
    }
    // 지후니
    while(!Q2.empty()){
        pair<int,int> cur = Q2.front(); Q2.pop();
        for(int i = 0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c){ //범위를 벗어남은 탈출 성공임 - 탈출 조건
                cout << dist2[cur.X][cur.Y] + 1;
                return 0;
            }
            if(dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if(dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y]+1) continue;
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            Q2.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE"; //탈출 불가능
    return 0;
}
