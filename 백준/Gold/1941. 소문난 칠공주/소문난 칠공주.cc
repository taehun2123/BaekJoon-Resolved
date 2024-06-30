#include <bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;

bool state[25];
string board[5];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
        cin >> board[i];

    fill(state + 7, state+25, true);
    do {
        queue<pii> Q;
        int dasom = 0;
        int adj = 0;
        bool isp7[5][5] = {};
        bool vis[5][5] = {};
        for(int x = 0; x<5; x++){
            for(int y = 0; y<5; y++){
                int i = x * 5 + y;
                if(state[i]) continue;
                isp7[x][y] = true;
                if(Q.empty()) {
                    Q.push({x, y});
                    vis[x][y] = true;
                }
            }
        }
        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            adj++;
            dasom += board[cur.X][cur.Y] == 'S';
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                if(vis[nx][ny] || !isp7[nx][ny]) continue;
                Q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
        ans += (adj >= 7 && dasom >= 4);
    } while(next_permutation(state, state + 25));

    cout << ans;

    return 0;
}
