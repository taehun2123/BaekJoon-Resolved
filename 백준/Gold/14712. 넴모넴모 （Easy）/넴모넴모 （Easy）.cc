#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int dx[3] = {-1, 0, -1};
int dy[3] = {0, -1, -1};
int board[26][26];
bool check(int x, int y){
    int cnt = 0;
    for(int dir = 0; dir<3; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(board[nx][ny]) cnt++;
    }
    if(cnt == 3) return false;
    return true;
}

void tracking(int x, int y){
    if(x == n-1 && y == m){ // 범위의 끝, 경우의 수 1을 추가하고 재귀를 끝낸다.
        ans++;
        return;
    }
    if(y == m){ //가로로 계속 진행한다. 가로의 범위가 넘어갈 때면, 가로를 초기화하고 x를 한칸 내려서 확인한다.
        y = 0;
        x++;
    }
    board[x][y] = 1;
    if(check(x,y)) tracking(x, y+1); //2*2가 안 만들어질 때 넴모를 올린다.
    board[x][y] = 0;
    tracking(x, y+1); // 현재 칸에는 넴모를 올리지 않고 넘어간다.
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    tracking(0, 0);
    cout << ans;
    return 0;
}
