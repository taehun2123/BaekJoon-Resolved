#include <bits/stdc++.h>
using namespace std;
int dp[505][505];
int tr[505][505];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 1; i<=N; i++)
        for(int j = 1; j<=i; j++)
            cin >> tr[i][j];

    dp[1][1] = tr[1][1];

    for(int i = 2; i<=N; i++){
        for(int j = 1; j<=i; j++){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + tr[i][j];
        }
    }

    cout << *max_element(dp[N]+1, dp[N] + N+1);

    return 0;
}