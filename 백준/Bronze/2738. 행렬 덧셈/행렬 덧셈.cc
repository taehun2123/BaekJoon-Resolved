#include <bits/stdc++.h>
using namespace std;
int N, M;
int board[101][101];
int boardB[101][101];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++) {
            cin >> boardB[i][j];
            board[i][j] += boardB[i][j];
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }



    return 0;
}
