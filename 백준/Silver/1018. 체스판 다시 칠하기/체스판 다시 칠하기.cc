#include <bits/stdc++.h>
using namespace std;
char board[51][51];
int integerBoard[51][51];
int check[51][51];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m, ans;
    int res = 64; // 칸의 최대값
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        cin >> board[i];
    }
    char WB[8][8] = {
            'W','B','W','B','W','B','W','B',
            'B','W','B','W','B','W','B','W',
            'W','B','W','B','W','B','W','B',
            'B','W','B','W','B','W','B','W',
            'W','B','W','B','W','B','W','B',
            'B','W','B','W','B','W','B','W',
            'W','B','W','B','W','B','W','B',
            'B','W','B','W','B','W','B','W'
    };
    char BW[8][8] = {
            'B','W','B','W','B','W','B','W',
            'W','B','W','B','W','B','W','B',
            'B','W','B','W','B','W','B','W',
            'W','B','W','B','W','B','W','B',
            'B','W','B','W','B','W','B','W',
            'W','B','W','B','W','B','W','B',
            'B','W','B','W','B','W','B','W',
            'W','B','W','B','W','B','W','B'
    };
    //기존 판이랑 비교
    for (int i = 0; i <= n - 8; i++) { //최소 8*8비교
        for (int j = 0; j <= m - 8; j++) {
            int cnt_w = 0, cnt_b = 0; //갯수 초기화

            for (int x = 0; x < 8; x++) { //완본 체스판 비교 반복문
                for (int y = 0; y < 8; y++) {
                    if (board[i + x][j + y] != BW[x][y]) { //BW랑 비교
                        cnt_b++;
                    }
                    if (board[i + x][j + y] != WB[x][y]) { //WB랑 비교
                        cnt_w++;
                    }
                }
            }
            //기준 체스판을 기준으로 모두 비교한다음에 최소값만 기록하기 위해 비교
            ans = min(cnt_b, cnt_w);
            if (ans <= res) {
                res = ans;
            }
        }
    }
    cout << res;
}
