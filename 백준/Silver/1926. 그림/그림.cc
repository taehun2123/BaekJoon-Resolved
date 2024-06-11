#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int board[505][505];
bool vis[505][505];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> board[i][j];
        }
    }
    int mx = 0;
    int cnt = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(board[i][j] == 0 || vis[i][j]) continue;
            cnt++;
            queue<pair<int,int>> Q;
            vis[i][j] = 1;
            Q.push({i,j});
            int area = 0;
            while(!Q.empty()){
                area++;
                pair<int,int>cur = Q.front();
                Q.pop();
                for(int i = 0; i<4; i++){
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];
                    if(nx < 0 || nx >= n || ny < 0 || ny >=m) continue;
                    if(board[nx][ny] != 1 || vis[nx][ny] == 1) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            //넓이 계산 - 최대값 구하기
            mx = max(mx,area);
        }
    }
    cout << cnt << "\n" << mx;
    return 0;
}
