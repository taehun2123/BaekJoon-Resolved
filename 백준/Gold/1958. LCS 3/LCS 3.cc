#include <bits/stdc++.h>
using namespace std;
string firstStr;
string secondStr;
string thirdStr;
int dp[102][102][102];
int ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> firstStr >> secondStr >> thirdStr;
    for(int i = 1; i <= firstStr.size(); i++){
        for(int j = 1; j<=secondStr.size(); j++){
            for(int k = 1; k<=thirdStr.size(); k++){
                if(firstStr[i-1] == secondStr[j-1] && secondStr[j-1] == thirdStr[k-1]) dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else dp[i][j][k] = max(dp[i][j][k-1], max(dp[i-1][j][k], dp[i][j-1][k]));
            }
            //부분 수열은 연속된 값이 아니므로, 이전의 최대 공통부분 수열을 가져오기 위함
        }
    }
    cout << dp[firstStr.size()][secondStr.size()][thirdStr.size()] << "\n";

    return 0;
}
