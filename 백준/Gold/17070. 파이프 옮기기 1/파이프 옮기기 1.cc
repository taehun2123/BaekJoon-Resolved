#include <bits/stdc++.h>
#define tii tuple<int,int,int> // 0 - 가로, 1 - 세로, 2 - 대각선
using namespace std;
int board[20][20];
int dx[3] = {0, 1, 1};
int dy[3] = {1, 1, 0};
int n, ans;
queue<tii> Q;
void moved(int x, int y, int dir){
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (board[nx][ny] == 0 && nx > 0 && nx <= n && ny > 0 && ny <= n) {
        if (dir == 1) {
            if (board[nx - 1][ny] == 1 || board[nx][ny - 1] == 1)
                return;
        }
        Q.push({ nx, ny, dir });
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++)
            cin >> board[i][j];
    Q.push({1, 2, 0});

    while(!Q.empty()){
        int x, y, d;
        tie(x,y,d) = Q.front(); Q.pop();
        if(x == n && y == n) ans++;
        if(d==0){
            for(int dir = 0; dir<2; dir++){
                moved(x, y, dir);
            }
        } else if(d==1){ //대각선
            for(int dir = 0; dir<3; dir++){
                moved(x, y, dir);
            }
        } else {
            for(int dir = 1; dir<3; dir++){
                moved(x, y, dir);
            }
        }

    }
    cout << ans;
    return 0;
}
