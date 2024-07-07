#include <bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;
int board[21][21];
int vis[21][21];
int dx[4] = {-1, 0, 0, 1}; //상 -> 좌 -> 우 -> 하
int dy[4] = {0, -1, 1, 0};
int cntEat;
int curShark = 2;
int ans, curx, cury;
int n;

int BFS() {
    for(int i = 0; i<n; i++)
        fill(vis[i], vis[i]+n, false);
    queue<pii> Q;
    int dist = 0; //최단거리
    // <큐의 자료형, 큐의 구현체(vector), 비교연산자> - 상어가 먹을 수 있는 물고기들의 위치
    priority_queue<pii, vector<pii>, greater<pii>> pq; //우선순위 큐 ( 최단거리인 것들만) - 내림차순
    Q.push({curx, cury});
    vis[curx][cury] = 1;
    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        if (vis[cur.X][cur.Y] == dist) break; //최단 거리 내에 있는 물고기를 모두 찾으면 빠져나감
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny]) continue;
            if(!board[nx][ny] || board[nx][ny] == curShark){ // 0이거나 현재 아기상어 크기와 같은 물고기일 때(지나갈 수 있음)
                vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                Q.emplace(nx, ny);
            }
            else if (board[nx][ny] < curShark) { //아기상어보다 작은 물고기들에 대하여
                if (!dist) cntEat++;
                vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                dist = vis[nx][ny];
                pq.emplace(nx, ny);
            }
        }
    }
    if(pq.empty()) return 0;
    curx = pq.top().first;
    cury = pq.top().second;
    board[curx][cury] = 0;
    if(cntEat == curShark){
        curShark++;
        cntEat = 0;
    }
    return vis[curx][cury] - 1; //처음 위치가 포함되어 있기 때문에 -1
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    queue<pii > Q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                curx = i;
                cury = j;
                board[i][j] = 0;
            }
        }
    }
    while (1) {
        int sec = BFS();
        ans += sec;
        if (!sec) break;
    }
    cout << ans;
    return 0;
}
