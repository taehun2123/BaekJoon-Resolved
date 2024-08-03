#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int dp[10002] = {0};
        dp[0] = 1; // 0->n 개를 만드는 경우의 수 = 1;
        for(int i = 1; i<=3; i++){
            for(int j = i; j<=n; j++){
                dp[j] += dp[j-i];
            }
        }
        cout << dp[n] << "\n";
    }
    return 0;
}
