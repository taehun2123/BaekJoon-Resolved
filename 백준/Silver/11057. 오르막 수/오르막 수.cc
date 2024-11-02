#include <bits/stdc++.h>
using namespace std;
#define MOD 10007

int sol(int n) {
    int dp[10];
    fill(dp, dp + 10, 1);

    for(int i = 1; i < n; i++) {
        // 기존 배열을 누적합으로 바꾼다.
        // 우리가 알고자 하는 것은 N = n일때의 배열의 전체 합이기 때문에
        // 중간 배열을 저장할 필요도 없고, 저장해둘 필요도 없다.
        for(int j = 0; j < 9; j++) {
            dp[j + 1] += dp[j] % MOD;
            dp[j + 1] %= MOD;
        }
    }
    return accumulate(dp, dp + 10, 0) % MOD;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    cout << sol(n);
}