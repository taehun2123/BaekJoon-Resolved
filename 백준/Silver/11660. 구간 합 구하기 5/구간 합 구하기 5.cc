#include <bits/stdc++.h>
using namespace std;
int n, m;
int arrN[1027][1027];
int d[1027][1027];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >> arrN[i][j];
            d[i][j] = d[i-1][j] + d[i][j-1] - d[i-1][j-1] + arrN[i][j];
        }
    }
    while(m--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << d[x2][y2] - d[x1-1][y2] - d[x2][y1-1] + d[x1-1][y1-1] << '\n';
    }
    return 0;
}
