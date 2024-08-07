#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int MAX = 1002;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char mapp[MAX][MAX];  
int board[MAX][MAX];  
int vis[MAX][MAX];    
int area[1000002];    
int ans[MAX][MAX];    

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> mapp[i];
    }

    int num = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mapp[i][j] == '1' || vis[i][j]) continue;
            num++;
            queue<pair<int,int>> Q;
            Q.push({i,j});
            vis[i][j] = 1;
            int cnt = 1;
            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                board[cur.X][cur.Y] = num;

                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(mapp[nx][ny] == '1' || vis[nx][ny]) continue;
                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                    cnt++;
                }
            }
            area[num] = cnt;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mapp[i][j] == '0') continue;
            int sum = 1;
            set<int> uq;
            for(int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(mapp[nx][ny] == '1') continue;
                if(uq.find(board[nx][ny]) == uq.end()) {
                    sum += area[board[nx][ny]];
                    uq.insert(board[nx][ny]);
                }
            }
            ans[i][j] = sum;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mapp[i][j] == '1') {
                cout << ans[i][j] % 10;
            } else {
                cout << '0';
            }
        }
        cout << "\n";
    }

    return 0;
}
