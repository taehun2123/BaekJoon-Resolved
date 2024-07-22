#include <bits/stdc++.h>
#define pii pair<int, int>
#define X first
#define Y second
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[102][102];
bool vis[102][102];
int N, M, ans;
vector<pii> key[102][102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    while (M--) {
        int fa, fb, ta, tb;
        cin >> fa >> fb >> ta >> tb;
        key[fa][fb].push_back({ta, tb});
    }
    queue<pii> Q;
    set<pii> lightOn;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            if (i == 1 && j == 1) continue;
            board[i][j] = 1; // 첫 위치를 제외한 나머지 장소에는 불이 꺼져있음(1)
        }

    Q.push({1, 1});
    vis[1][1] = 1;
    board[1][1] = 0;
    ans = 1;

    while (!Q.empty()) {
        bool turnedOnLight = false;
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            for (auto switch_loc : key[cur.X][cur.Y]) {
                if (board[switch_loc.X][switch_loc.Y] == 1) {
                    board[switch_loc.X][switch_loc.Y] = 0;
                    ans++;
                    turnedOnLight = true;
                    lightOn.insert({switch_loc.X, switch_loc.Y});
                }
            }
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx <= 0 || nx > N || ny <= 0 || ny > N) continue;
                if (vis[nx][ny]) continue;
                if (board[nx][ny] == 1) continue;
                Q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }

        if (!turnedOnLight) break;

        for (auto litRoom : lightOn) {
            int lx = litRoom.X, ly = litRoom.Y;
            if (vis[lx][ly]) continue;
            for (int dir = 0; dir < 4; dir++) {
                int nx = lx + dx[dir];
                int ny = ly + dy[dir];
                if (nx <= 0 || nx > N || ny <= 0 || ny > N) continue;
                if (vis[nx][ny]) {
                    Q.push({lx, ly});
                    vis[lx][ly] = 1;
                    break;
                }
            }
        }
        lightOn.clear();
    }
    cout << ans;
    return 0;
}
