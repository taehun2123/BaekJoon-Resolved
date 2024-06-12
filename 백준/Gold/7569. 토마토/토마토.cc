#include <bits/stdc++.h>
#define X get<0>
#define Y get<1>
#define Z get<2>
using namespace std;

int n, m, h;
int board[101][101][101];
int dist[101][101][101];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> h;
    queue<tuple<int, int, int>> Q;

    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[k][i][j];
                if (board[k][i][j] == 1) {
                    Q.emplace(i, j, k);
                }
                if (board[k][i][j] == 0) {
                    dist[k][i][j] = -1;
                }
            }
        }
    }

    while (!Q.empty()) {
        tuple<int, int, int> cur = Q.front(); Q.pop();
        for (int i = 0; i < 6; i++) {
            int nx = X(cur) + dx[i];
            int ny = Y(cur) + dy[i];
            int nz = Z(cur) + dz[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if (dist[nz][nx][ny] >= 0) continue;
            dist[nz][nx][ny] = dist[Z(cur)][X(cur)][Y(cur)] + 1;
            Q.emplace(nx, ny, nz);
        }
    }

    int ans = 0;
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dist[k][i][j] == -1) {
                    cout << -1;
                    return 0;
                }
                ans = max(ans, dist[k][i][j]);
            }
        }
    }

    cout << ans;
    return 0;
}
