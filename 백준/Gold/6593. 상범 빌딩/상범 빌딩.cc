#include <bits/stdc++.h>
#define X get<0>
#define Y get<1>
#define Z get<2>
using namespace std;
string board[32][32];
int dist[32][32][32];
int dx[6] = {1, 0 , -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int l, r, c;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true){
        bool flag = false;
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0) return 0;
        for(int i = 0; i<l; i++){
            for(int j = 0; j<r; j++){
                fill(dist[i][j], dist[i][j]+c, -1);
            }
        }
        for(int i = 0; i<l; i++){
            for(int j = 0; j<r; j++){
                cin >> board[i][j];
            }
        }
        queue<tuple<int,int,int>> Q;
        for(int i = 0; i<l; i++){
            for(int j = 0; j<r; j++){
                for(int k = 0; k<c; k++){
                    if(board[i][j][k] == 'S'){
                        Q.push({j, k, i});
                        dist[i][j][k]++;
                    }
                }
            }
        }
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(int i = 0; i<6; i++){
                int nx = X(cur) + dx[i];
                int ny = Y(cur) + dy[i];
                int nz = Z(cur) + dz[i];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) continue;
                if(board[nz][nx][ny] == '#' || dist[nz][nx][ny] >= 0) continue;
                if(board[nz][nx][ny] == 'E'){
                    cout << "Escaped in " << dist[Z(cur)][X(cur)][Y(cur)]+1 << " minute(s)." << "\n";
                    flag = true;
                    break;
                }
                dist[nz][nx][ny] = dist[Z(cur)][X(cur)][Y(cur)]+1;
                Q.push({nx, ny, nz});
            }
            if(flag) break;
        }
        if(flag) continue;
        cout << "Trapped!" << "\n";
    }
}
