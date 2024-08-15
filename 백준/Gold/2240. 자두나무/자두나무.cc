#include <bits/stdc++.h>
using namespace std;
int T, W, ans;
int tree[1002];
int dp[3][1002][32]; // 순서대로 P T W - T시간에 P에 있고 W번 더 움직을 수 있을 때 경우의 수
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T >> W;
    for(int i = 1; i<=T; i++) cin >> tree[i];

    /** 구분
     * - 1. 현재 자두의 위치와 떨어지는 나무 위치가 같았을 때
     * -- 자두를 먹고 자리를 옮겼을 상황과, 먹고 자리를 안 옮기는 상황
     * - 2. 현재 자두의 위치와 떨어지는 나무 위치가 달랐을 때
     * -- 자두를 못 먹고 자리를 옮겼을 상황과, 못 먹고 자리를 안 옮기는 상황
     */
    //
    for(int i = 1; i<=T; i++){
        dp[1][i][0] = dp[1][i-1][0] + (tree[i] == 1 ? 1 : 0);
        for(int j = 1; j<=W; j++){
            if(i<j) break;
            if(tree[i] == 1){
                dp[1][i][j] = max(dp[2][i-1][j-1], dp[1][i-1][j]) + 1;
                dp[2][i][j] = max(dp[1][i-1][j-1], dp[2][i-1][j]);
            }
            else{
                dp[1][i][j] = max(dp[2][i-1][j-1], dp[1][i-1][j]);
                dp[2][i][j] = max(dp[1][i-1][j-1], dp[2][i-1][j]) + 1;
            }
        }
    }


    for(int i = 0; i<=W; i++){
        ans = max(ans, dp[1][T][i]);
        ans = max(ans, dp[2][T][i]);
    }
    cout << ans;

    return 0;
}
