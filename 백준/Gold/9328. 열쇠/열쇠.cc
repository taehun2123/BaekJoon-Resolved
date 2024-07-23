#include <bits/stdc++.h>
#define pii pair<int, int>
#define X first
#define Y second
using namespace std;

int T, h, w;
char board[102][102];
bool vis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;

    while (T--) {
        cin >> h >> w;

        // 초기화
        for (int i = 0; i < h; ++i) {
            fill(vis[i], vis[i] + w, false);
            fill(board[i], board[i] + w, 0);
        }

        int ans = 0;
        queue<pii> Q;
        vector<pii> door;
        vector<char> key;

        // 보드 입력
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                cin >> board[i][j];

        // 초기 열쇠
        string kk;
        cin >> kk;
        key.assign(kk.begin(), kk.end());

        // 가장자리에서 시작하여 큐 초기화
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if ((i == 0 || i == h - 1 || j == 0 || j == w - 1) && board[i][j] != '#') {
                    if (board[i][j] == '.' || board[i][j] == '$' || islower(board[i][j]) ||
                        (isupper(board[i][j]) && find(key.begin(), key.end(), tolower(board[i][j])) != key.end())) {
                        if (board[i][j] == '$') ++ans;
                        else if (islower(board[i][j])) key.push_back(board[i][j]);
                        board[i][j] = '.';
                        Q.push({i, j});
                        vis[i][j] = true;
                    } else if (isupper(board[i][j])) {
                        door.push_back({i, j});
                    }
                }
            }
        }

        // BFS를 사용하여 그리드 탐색
        while (!Q.empty()) {
            bool isGet = false;
            auto cur = Q.front(); Q.pop();
            for (int dir = 0; dir < 4; ++dir) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w || vis[nx][ny] || board[nx][ny] == '*') continue;

                if (board[nx][ny] == '.' || board[nx][ny] == '$' || islower(board[nx][ny]) ||
                    (isupper(board[nx][ny]) && find(key.begin(), key.end(), tolower(board[nx][ny])) != key.end())) {
                    if (board[nx][ny] == '$') ++ans;
                    else if (islower(board[nx][ny])) {
                        key.push_back(board[nx][ny]);
                        isGet = true;
                    }
                    board[nx][ny] = '.';
                    Q.push({nx, ny});
                    vis[nx][ny] = true;
                } else if (isupper(board[nx][ny])) {
                    door.push_back({nx, ny});
                }
            }
            // 새로운 열쇠를 얻었을 때 문 다시 탐색
            if (isGet) {
                for (auto dr : door) {
                    int drx = dr.X;
                    int dry = dr.Y;
                    if (find(key.begin(), key.end(), tolower(board[drx][dry])) != key.end()) {
                        board[drx][dry] = '.';
                        Q.push({drx, dry});
                        vis[drx][dry] = true;
                        remove(door.begin(), door.end(),dr);
                    }
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
