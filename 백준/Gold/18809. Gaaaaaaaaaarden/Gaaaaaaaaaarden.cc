#include <bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;

int n, m;
int board[51][51];
int cp_board[51][51];
int visRed[51][51];
int visGreen[51][51];
bool vis[51][51];
int gCnt, rCnt, ans;
int dx[4] = {1, 0, -1 ,0};
int dy[4] = {0, 1, 0, -1};
vector<pii> seed_ground;
vector<int> green;
vector<int> red;

void BFS() {
    queue<pii> G_Q;
    queue<pii> R_Q;
    int flower = 0;

    for (int i = 0; i < gCnt; i++) {
        visGreen[seed_ground[green[i]].X][seed_ground[green[i]].Y] = 1;
        G_Q.push({seed_ground[green[i]].X, seed_ground[green[i]].Y});
    }
    for (int i = 0; i < rCnt; i++) {
        visRed[seed_ground[red[i]].X][seed_ground[red[i]].Y] = 1;
        R_Q.push({seed_ground[red[i]].X, seed_ground[red[i]].Y});
    }

    while (!G_Q.empty() || !R_Q.empty()) {
        int g_size = G_Q.size();
        for (int k = 0; k < g_size; k++) {
            auto cur = G_Q.front(); G_Q.pop();
            if (cp_board[cur.X][cur.Y] == -1) continue;
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (visGreen[nx][ny] != 0 || cp_board[nx][ny] == 0) continue;
                visGreen[nx][ny] = visGreen[cur.X][cur.Y] + 1;
                G_Q.push({nx, ny});
            }
        }

        int r_size = R_Q.size();
        for (int j = 0; j < r_size; j++) {
            auto cur = R_Q.front(); R_Q.pop();
            if (cp_board[cur.X][cur.Y] == -1) continue;
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (visRed[nx][ny] != 0 || board[nx][ny] == 0) continue;
                if (visGreen[nx][ny] != 0 && visGreen[nx][ny] == visRed[cur.X][cur.Y] + 1) {
                    cp_board[nx][ny] = -1;
                    visRed[nx][ny] = visRed[cur.X][cur.Y] + 1;
                    flower++;
                    continue;
                }
                visRed[nx][ny] = visRed[cur.X][cur.Y] + 1;
                R_Q.push({nx, ny});
            }
        }
    }
    ans = max(ans, flower);
}

void board_reset() {
    memset(visGreen, 0, sizeof(visGreen));
    memset(visRed, 0, sizeof(visRed));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cp_board[i][j] = board[i][j];
        }
    }
}

void trackingRed(int st, int cnt) {
    if (cnt == rCnt) {
        BFS();
        board_reset();
        return;
    }
    for (int i = st; i < seed_ground.size(); i++) {
        if (vis[seed_ground[i].X][seed_ground[i].Y]) continue;
        vis[seed_ground[i].X][seed_ground[i].Y] = 1;
        red.push_back(i);
        trackingRed(i + 1, cnt + 1);
        red.pop_back();
        vis[seed_ground[i].X][seed_ground[i].Y] = 0;
    }
}

void trackingGreen(int st, int cnt) {
    if (cnt == gCnt) {
        trackingRed(0, 0);
        return;
    }
    for (int i = st; i < seed_ground.size(); i++) {
        if (vis[seed_ground[i].X][seed_ground[i].Y]) continue;
        vis[seed_ground[i].X][seed_ground[i].Y] = 1;
        green.push_back(i);
        trackingGreen(i + 1, cnt + 1);
        green.pop_back();
        vis[seed_ground[i].X][seed_ground[i].Y] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> gCnt >> rCnt;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            cp_board[i][j] = board[i][j];
            if (board[i][j] == 2) {
                seed_ground.push_back({i, j});
            }
        }
    }
    trackingGreen(0, 0);
    cout << ans;
    return 0;
}
