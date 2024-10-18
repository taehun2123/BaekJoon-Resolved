#include <bits/stdc++.h>
using namespace std;
int board[100002];
int N, K;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    fill(board, board + 100002, -1);
    board[N] = 0;
    queue<int> Q;
    Q.push(N);
    while(board[K] == -1){
        int cur = Q.front(); Q.pop();
        for(auto nx : {cur-1, cur+1, 2*cur}) {
            if(nx < 0 || nx > 100000 || board[nx] != -1) continue;
            board[nx] = board[cur] + 1;
            Q.push(nx);
            if(nx == K) break;
        }
    }
    cout << board[K];

    return 0;
}
