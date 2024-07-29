#include <bits/stdc++.h>
using namespace std;
string firstStr;
string secondStr;
string result;
int dp[1002][1002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> firstStr >> secondStr;
    unsigned long fSize = firstStr.size();
    unsigned long sSize = secondStr.size();
    for(int i = 1; i <= fSize; i++) {
        for(int j = 1; j <= sSize; j++) {
            if(firstStr[i-1] == secondStr[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int i = fSize, j = sSize;
    while(i > 0 && j > 0) { //i와 j가 0이 되면 종료
        if(firstStr[i-1] == secondStr[j-1]) {
            result.push_back(firstStr[i - 1]);
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }

    reverse(result.begin(), result.end());
    cout << dp[firstStr.size()][secondStr.size()] << "\n";
    cout << result;

    return 0;
}
