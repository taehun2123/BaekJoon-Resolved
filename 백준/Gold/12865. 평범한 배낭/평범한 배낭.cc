#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n, k;
int w[102];
int v[102];
int dp[102][100002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k; //n 개수, k 최대 무게
    for(int i = 1; i<=n; i++){
        cin >> w[i] >> v[i]; //w = 무게, v = 가치
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=k; j++){
            if(j >= w[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i]] + v[i]) ;
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][k];
    return 0;
}
