#include <bits/stdc++.h>
using namespace std;
long long dp[1000001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[1] = 1;
    dp[2] = 2;
    int N;
    cin >> N;
    for(int i = 3; i<=1000000; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    }
    cout << dp[N];
    return 0;
}
