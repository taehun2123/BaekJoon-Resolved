#include <bits/stdc++.h>
using namespace std;
int d[41][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    d[0][0] = 1;
    d[0][1] = 0;
    d[1][0] = 0;
    d[1][1] = 1;

    for(int i = 2; i<=40; i++){
        d[i][0] = d[i-2][0] + d[i-1][0];
        d[i][1] = d[i-2][1] + d[i-1][1];
    }

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        cout << d[n][0] << " " << d[n][1] << "\n";
    }
    return 0;
}
