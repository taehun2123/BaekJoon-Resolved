#include <bits/stdc++.h>
using namespace std;
int dp[302][3];
int stair[302];
//int dp[302]; // i번째 계단까지 올라섰을 때 밟지 않을 계단의 합의 최솟값, 단, i번째 계단은 반드시 밟지 않을 계단으로 선택해야 함
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, tot = 0;
    cin >> n;
    for(int i = 1; i<=n; i++) {
        cin>>stair[i];
        tot += stair[i];
    }
//    if(n <= 2){
//        cout << tot;
//        return 0;
//    }
//    dp[1] = stair[1];
//    dp[2] = stair[2];
//    dp[3] = stair[3];
//    for(int i = 4; i<=n; i++) dp[i] = min(dp[i-2], dp[i-3]) + stair[i];
//
//    cout << tot - min(dp[n-1], dp[n-2]);


    if(n==1){
        cout << stair[1];
        return 0;
    }
    // j개의 계단을 연속해서 밟고 i번째 계단까지 올라섰을 때 합의 최댓값
    // 단, i번째 계단은 무조건 밟아야 함
    dp[1][1] = stair[1];
    dp[1][2] = 0;
    dp[2][1] = stair[2];
    // 1개의 계단을 연속해서 밟고 2번째 계단에 올라섰을 때
    // - 하지만 i번째 계단을 무조건 밟아야함 조건으로 인해 그냥 바로 2번째 계단을 밟은 것과 같다
    dp[2][2] = stair[1] + stair[2]; // 2개의 계단을 연속해서 밟고 2번째 계단에 올라섰을 때

    for(int i=3; i<=n; i++){
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + stair[i];
        dp[i][2] = dp[i-1][1] + stair[i];
    }
    cout << max(dp[n][1], dp[n][2]);
    return 0;

}
