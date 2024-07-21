#include <bits/stdc++.h>
#define tii tuple<int,int, int>
#define X first
#define Y second
using namespace std;

int N, M, P;
long long S[12];
int ans[12];
char board[1002][1002];
bool vis[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<tii> Q[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> P;
    for(int i = 1; i <= P; i++){
        cin >> S[i];
    }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            if(board[i][j]-'0' >= 1 && board[i][j]-'0' <= 9) {
                int player = board[i][j] - '0';
                Q[player].push({i, j, 0});
                ans[player]++;
            }
        }


    while(true){
        bool anyMove = false;
        for(int k = 1; k <= P; k++) {
            queue<tii> nextQ;
            while(!Q[k].empty()) {
                int curX, curY, curS;
                tie(curX, curY, curS) = Q[k].front(); Q[k].pop();
                if(curS >= S[k]){
                    nextQ.push({curX, curY, 0});
                    continue;
                }
                for(int dir = 0; dir < 4; dir++) {
                    int nx = curX + dx[dir];
                    int ny = curY + dy[dir];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if(board[nx][ny] == '.') {
                        Q[k].push({nx, ny, curS+1});
                        board[nx][ny] = board[curX][curY];
                        ans[k]++;
                        anyMove = true;
                    }
                }
            }
            Q[k] = nextQ;
        }
        if(!anyMove) break;
    }

    for(int i = 1; i <= P; i++){
        cout << ans[i] << ' ';
    }

    return 0;
}