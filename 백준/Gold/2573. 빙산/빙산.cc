#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int board[305][305];
int vis[305][305];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n,m,cnt;

bool check(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void initvis(){
    for(int i = 0; i < n; i++) fill(vis[i], vis[i] + m, 0);
}

// 1년의 시간 흐름을 진행
void melting(){
    int zero[303][303] = {0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0) continue;
            for(int dir = 0; dir < 4; dir++){ // 주변의 0의 개수를 센다
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(check(nx, ny) && board[nx][ny] == 0) zero[i][j]++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            board[i][j] = max(0, board[i][j] - zero[i][j]);
    }
}

// 0 : 빙산이 다 녹음, 1 : 아직 한 덩이, 2 : 분리됨
int status() {
    int x = -1, y = -1;
    int cnt1 = 0; // 빙산의 개수
    // 빙산이 남아있는 아무 칸 선택
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j]) {
                x = i;
                y = j;
                cnt1++;
            }
        }
    }
    if (cnt1 == 0) return 0; // 빙산이 남아있는 칸이 없음
    int cnt2 = 0; // (x, y)와 붙어있는 빙산의 수
    queue<pair<int, int> > q;
    vis[x][y] = 1; // 현재 위치 방문
    q.push({x, y});
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        cnt2++;
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (!check(nx, ny) || vis[nx][ny] == 1 || board[nx][ny] <= 0) continue; // 범위, 방문, 이동가능 여부 체크
            vis[nx][ny] = 1; // 방문표시
            q.push({nx, ny}); // 이동
        }
    }
    if (cnt1 == cnt2) return 1; // 전체 빙산의 수와 (x, y)와 붙어있는 빙산의 수가 일치하므로 아직 한 덩이
    return 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> board[i][j];
        }
    }
    while(true){
        cnt++;
        melting();
        initvis();
        int check = status(); // 빙산의 상태 확인
        if(check == 0) {
            cout << 0;
            return 0;
        }
        else if(check == 1) continue; // 아직 한 덩이
        else break; // check = 2, 분리됨
    }
        cout << cnt;
        return 0;
}
