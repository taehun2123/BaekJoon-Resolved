#include <bits/stdc++.h>
using namespace std;

vector<int> friends[30001];
int dp[30001][3001];
int vis[30001];
vector<pair<int, int>> group;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> candies(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> candies[i];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        queue<int> Q;
        vis[i] = 1;
        int sumCandy = candies[i];
        int num = 1;
        Q.push(i);
        while (!Q.empty()) {
            int cur = Q.front(); Q.pop();
            for (auto e: friends[cur]) {
                if (vis[e]) continue;
                vis[e] = 1;
                sumCandy += candies[e];
                num++;
                Q.push(e);
            }
        }
        if (num <= k) {
            group.push_back({sumCandy, num});
        }
    }

    for (int i = 1; i <= group.size(); i++) {
        int group_candies = group[i - 1].first;
        int group_size = group[i - 1].second;
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i-1][j];
            if (j > group_size) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - group_size] + group_candies);
            }
        }
    }

    cout << dp[group.size()][k] << "\n";
    return 0;
}
