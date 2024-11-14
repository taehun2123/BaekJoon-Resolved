#include <bits/stdc++.h>
using namespace std;
int n, k;
int val[102]; //동전의 가치
int dp[10002]; // 가치의 합이 k일 때의 경우의 수
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    dp[0] = 1; // 가치의 합이 0이면 동전 0개를 사용한 경우의 수는 1임
    for(int i = 1; i<=n; i++) cin >> val[i];
    for(int i = 1; i<=n; i++)
        for(int j = val[i]; j<=k; j++)
            dp[j] += dp[j-val[i]];

    cout << dp[k];
    return 0;
}
