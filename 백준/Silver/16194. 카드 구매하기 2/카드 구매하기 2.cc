#include <bits/stdc++.h>
using namespace std;
/*
 * 카드 N개를 갖기위해 지불해야 하는 금액의 최댓값
 */
int dp[1001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; // 카드의 종류 n가지
    cin >> N;
    for(int i = 1; i<=N; i++) cin >> dp[i];
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=i; j++){
            dp[i] = min(dp[i], dp[i-j] + dp[j]);
        }
    }

    cout << dp[N];
    return 0;
}
