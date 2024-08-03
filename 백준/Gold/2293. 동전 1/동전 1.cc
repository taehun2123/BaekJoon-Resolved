#include <bits/stdc++.h>
using namespace std;
int n, k;
int v[102];
int dp[10002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i<=n; i++) cin >> v[i];
    dp[0] = 1;
    for(int i = 1; i<=n; i++){
        for(int j = v[i]; j<=k; j++){
            //가지고 있는 동전의 가장 작은 부분 부터 시작하여
            //목표 동전 가치인 k까지의 모든 경우의 수를 구한다.
            dp[j] += dp[j-v[i]];
        }
    }

    cout << dp[k];
    return 0;
}
