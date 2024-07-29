#include <bits/stdc++.h>
using namespace std;
string firstStr;
string secondStr;
int dp[1002][1002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> firstStr >> secondStr;
    for(int i = 1; i <= firstStr.size(); i++){
        for(int j = 1; j<=secondStr.size(); j++){
            if(firstStr[i-1] == secondStr[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            //부분 수열은 연속된 값이 아니므로, 이전의 최대 공통부분 수열을 가져오기 위함
        }
    }
    cout << dp[firstStr.size()][secondStr.size()];
    return 0;
}
