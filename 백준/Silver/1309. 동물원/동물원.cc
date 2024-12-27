#include <bits/stdc++.h>
using namespace std;
int dp[100001][3]; // 한 행에 사자를 놓을 수 있는 경우의 수 0, 1, 2 => 3가지의 경우 존재
int N;
int mod = 9901;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    dp[1][0] = 1; // o x -> 1, 2가 앞에 올 수 있음
    dp[1][1] = 1; // x o -> 0, 2가 앞에 올 수 있음
    dp[1][2] = 1; // x x -> 0, 1 ,2 모든 방법이 가능
    for(int i = 2; i<=N; i++){
        dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % mod;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % mod;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % mod;
    }

    cout << (dp[N][0] + dp[N][1] + dp[N][2])%mod;
    return 0;
}
