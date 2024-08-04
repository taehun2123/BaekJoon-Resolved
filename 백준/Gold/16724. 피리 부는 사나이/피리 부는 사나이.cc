#include <iostream>
using namespace std;

int board[1002][1002];
int vis[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, ans;

void dfs(int x, int y) {
    vis[x][y] = 1;
    int nx = x + dx[board[x][y]];
    int ny = y + dy[board[x][y]];

    if(vis[nx][ny] == 1) { // If the next cell is visited once, a cycle is detected
        ans++; 
        vis[nx][ny] = 2; // Mark it as fully visited to prevent reprocessing
    }
    if(vis[nx][ny] == 0) {
        dfs(nx, ny); // Continue DFS if the next cell is not visited
    }
    vis[x][y] = 2; // Mark the current cell as fully visited
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char a;
            cin >> a;
            if(a == 'U') board[i][j] = 2; // Up
            else if(a == 'L') board[i][j] = 3; // Left
            else if(a == 'R') board[i][j] = 1; // Right
            else board[i][j] = 0; // Down
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j] == 0) {
                dfs(i, j); // Start DFS from unvisited cells
            }
        }
    }

    cout << ans; // Output the number of cycles
    return 0;
}
