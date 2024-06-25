#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
string board[1502];
int vis[1502][1502];
int visi[1502][1502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int r,c,cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    queue<pii> Q;
    queue<pii> Q2;
    queue<pii> LQ;
    queue<pii> LQ2;

    bool isPossible = false;

    for(int i = 0; i<r; i++){
        cin >> board[i];
    }
    int lx,ly;
    for(int i = 0; i <r; i++){
        for(int j = 0; j<c; j++){
            if(board[i][j] == 'L'){
                lx = i;
                ly = j;
            }
            if(board[i][j] != 'X'){
                Q.push({i,j});
            }
        }
    }
    LQ.push({lx, ly});
    board[lx][ly] = '.';
    vis[lx][ly] = 1;
    while(!isPossible) {
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            visi[cur.X][cur.Y] = 1;
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if ((nx < 0 || nx >= r || ny < 0 || ny >= c) || visi[nx][ny] == 1) continue;
                if (board[nx][ny] == 'X') Q2.push({nx, ny});
                visi[nx][ny] = 1;
            }
        }
        while (!Q2.empty()) { //물 근처에 있던 빙하가 녹는 과정 (하루가 지남)
            auto cur = Q2.front();
            Q2.pop();
            board[cur.X][cur.Y] = '.';
            Q.push({cur.X, cur.Y});
        }
        cnt++;
        //백조 짝 맞추기
        while (!LQ.empty()) {
            auto cur = LQ.front();
            LQ.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c || vis[nx][ny] == 1) continue;
                if (board[nx][ny] == 'X') {
                    LQ2.push({nx, ny});
                    vis[nx][ny] = 1;
                    continue;
                } else if (board[nx][ny] == 'L') {
                    isPossible = true;
                    break;
                } else {
                    vis[nx][ny] = 1;
                    LQ.push({nx, ny});
                }
            }
        }
        while (!LQ2.empty()) { //빙하에 막혔던 지점으로 부터 하루가 지나면 녹기 때문에 다시 시작하기 위한 큐
            auto cur = LQ2.front(); LQ2.pop();
            LQ.push({cur.X, cur.Y});
        }
    }
    cout << cnt;
    return 0;
}
