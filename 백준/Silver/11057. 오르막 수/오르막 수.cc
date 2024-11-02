#include <bits/stdc++.h>
using namespace std;
int dp[1002][10]; // a자리에서 b가 마지막 수로 왔을 때의 오르막수의 개수
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ;i<10; i++) dp[1][i] = 1;

    for(int i = 2; i<=n; i++)
        for(int j = 0; j<10; j++)
            for(int k = 0; k<=j; k++){
                dp[i][j] += dp[i-1][k];
                dp[i][j] %= 10007;
            }


    int ans=0;
    for(int i = 0; i<10; i++) ans += dp[n][i];

    cout << ans % 10007;

    return 0;
}
