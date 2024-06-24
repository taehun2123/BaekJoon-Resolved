#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
string board[30];
int vis[30][30];
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> board[i];
    }
    int sum = 0;
    vector<int> arr;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(board[i][j] == '0' || vis[i][j] == 1) continue;
            queue<pair<int,int>> Q;
            Q.push({i, j});
            vis[i][j] = 1;
            sum++;
            int cnt = 0;
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                cnt++;
                for(int i = 0; i<4; i++){
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(board[nx][ny] == '0' || vis[nx][ny] == 1) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            arr.push_back(cnt);
        }
    }
    sort(arr.begin(), arr.end());
    cout << sum << "\n";
    for(auto i : arr){
        cout << i << "\n";
    }

    return 0;
}
