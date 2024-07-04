#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, m, mx;
int arr[10][10];
bool vis[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1,0, -1};
int bfs(){
    int cnt = 0;
    queue<pii> Q;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            if(arr[i][j] == 2){
                vis[i][j] =1;
                Q.push({i,j});
            }
        }

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(arr[nx][ny] > 0 || vis[nx][ny] == 1) continue;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(arr[i][j] == 0 && !vis[i][j]){
                cnt++;
            }
        }
    }
    return cnt;
}
void wall(int wallCnt){
    if(wallCnt == 3){
        memset(vis, 0, sizeof(vis));
        int cnt = bfs();
        mx = max(mx, cnt);
        return;
    }
    for(int i = 0; i<n; i++)
        for(int j = 0; j< m; j++){
            if(arr[i][j] == 0){
                arr[i][j] = 1;
                wall(wallCnt+1);
                arr[i][j] = 0;
            }
        }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    //벽 세우기
    wall(0);
    cout << mx;
    return 0;
}
