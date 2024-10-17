#include <bits/stdc++.h>
using namespace std;
int dp[1002][4]; //i번째 집까지 칠할때의 비용 최솟값, j는 색 0 = R 1 = G 2= B
int R[1002];
int G[1002];
int B[1002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 1; i<=N; i++) cin >> R[i] >> G[i] >> B[i];

    dp[1][0] = R[1];
    dp[1][1] = G[1];
    dp[1][2] = B[1];

    for(int i = 2; i<=N; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + R[i];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + G[i];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + B[i];
    }

    cout << *min_element(dp[N], dp[N]+3);
    return 0;
}
