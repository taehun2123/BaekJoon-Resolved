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
int area[1000002]; //그룹화 한 순환가능한 경로의 개수 배열
int ans[MAX][MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //입력
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> mapp[i];
    }

    //모든 0에 대해서 BFS, board 배열에는 그룹 번호를 표기함.
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
                board[cur.X][cur.Y] = num; //그룹 번호 표기

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
            // 하나의 그룹에 대한 BFS 값을 area에 저장 -
            // board 값이 해당 index라면 area[index]의 값이라고 판단
        }
    }

    //모든 벽('1')에 대하여 BFS - 같은 그룹에 대하여 한번만 적용하도록 로직 적용
    //ans배열에 주변 area[board[nx][ny]]의 합계 값을 저장 - 해당 벽에서 이동할 수 있는 개수임
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
                if(uq.find(board[nx][ny]) == uq.end()) { //이미 탐색하여 저장한 곳이 아니라면
                    sum += area[board[nx][ny]]; // sum 변수에 board[nx][ny]를 index로 하는 경로 수를 합
                    uq.insert(board[nx][ny]); // board[nx][ny] 라는 그룹은 적용완료 하였다고 표시
                }
            }
            ans[i][j] = sum; //결과값으로 sum을 부여
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
