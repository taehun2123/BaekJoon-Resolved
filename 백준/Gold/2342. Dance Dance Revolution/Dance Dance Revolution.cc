#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int dp[100002][5][5];

int calCost(int cur, int next){
    if(cur == 0) return 2;
    if(cur == next) return 1;
    if(abs(cur - next) == 2) return 4;
    return 3;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> sequence;
    int n;
    while(cin >> n && n != 0) {
        sequence.push_back(n);
    }

    int len = sequence.size();
    for (int i = 0; i <= len; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    dp[0][0][0] = 0;

    for (int i = 0; i < len; i++) {
        int next = sequence[i];
        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < 5; y++) {
                if (dp[i][x][y] >= INF) continue;
                int a = calCost(x, next);
                int b = calCost(y, next);
                dp[i + 1][x][next] = min(dp[i + 1][x][next], dp[i][x][y] + b);
                dp[i + 1][next][y] = min(dp[i + 1][next][y], dp[i][x][y] + a);
            }
        }
    }

    int ans = INF;
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            ans = min(ans, dp[len][x][y]);
        }
    }

    cout << ans << '\n';
    return 0;
}
