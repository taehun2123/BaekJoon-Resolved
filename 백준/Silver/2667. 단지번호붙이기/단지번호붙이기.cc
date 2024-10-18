#include <bits/stdc++.h>
using namespace std;
string board[30];
int nx[4] = {0, 1, 0, -1};
int ny[4] = {1, 0, -1, 0};
bool dist[30][30];
queue<pair<int,int>> Q;
vector<int> house;
int N, ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    //보드 그리기
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    //탐색
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            if (board[i][j] != '1' || dist[i][j]) continue;
            ans++;
            int size = 1;
            dist[i][j] = 1;
            Q.push({i, j});
            while (!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                size++;
                for (int k = 0; k < 4; k++) {
                    int nfx = cur.first + nx[k];
                    int nfy = cur.second + ny[k];
                    if (nfx < 0 || nfx >= N || nfy < 0 || nfy >= N) continue;
                    if (dist[nfx][nfy] || board[nfx][nfy] != '1') continue;
                    dist[nfx][nfy] = 1;
                    Q.push({nfx, nfy});
                }
            }
            house.push_back(size);
        }
    }
    sort(house.begin(), house.end());
    cout << ans << "\n";
    for(auto x: house){
        cout << x-1 << "\n";
    }
    return 0;
}
