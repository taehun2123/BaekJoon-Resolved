#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n;
        vector<int> coins(n + 1);
        for(int i = 1; i <= n; i++) cin >> coins[i];
        cin >> m;
        vector<int> dp(m + 1, 0);
        dp[0] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = coins[i]; j <= m; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }

        cout << dp[m] << "\n";
    }

    return 0;
}
