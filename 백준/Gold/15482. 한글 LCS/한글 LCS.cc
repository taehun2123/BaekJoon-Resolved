#include <bits/stdc++.h>
using namespace std;
string firstStr;
string secondStr;
int ans;
int dp[5002][5002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> firstStr >> secondStr;
    int size = 3;
    for(int i = 3; i <= firstStr.size(); i+=size){
        for(int j = 3; j<=secondStr.size(); j+=size){
            if(firstStr.substr(i-3, size) == secondStr.substr(j-3, size)) dp[i][j] = dp[i-3][j-3] + 1;
            else dp[i][j] = max(dp[i-3][j], dp[i][j-3]);
            //부분 수열은 연속된 값이 아니므로, 이전의 최대 공통부분 수열을 가져오기 위함
        }
    }
    cout << dp[firstStr.size()][secondStr.size()];

    return 0;
}
