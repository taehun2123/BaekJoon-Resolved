#include <bits/stdc++.h>
using namespace std;
int dp[1002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i = 4; i<=1001; i++){
        dp[i] = (dp[i-2] + dp[i-1]) % 10007;
    }
    int n;
    cin >> n;
    cout << dp[n];


    return 0;
}
