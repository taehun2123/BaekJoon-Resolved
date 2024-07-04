#include <bits/stdc++.h>
using namespace std;
int T, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        int d[2][100002] = {0, };
        int arr[2][100002] = {0, };

        for(int i = 0; i <= 1; i++)
            for (int j = 1; j <= n; j++)
                cin >> arr[i][j];

        d[0][0] = d[1][0] = 0;
        d[0][1] = arr[0][1];
        d[1][1] = arr[1][1];
        for (int i = 2; i <= n; i++){
            d[0][i] = max(d[1][i-1], d[1][i-2]) + arr[0][i];
            d[1][i] = max(d[0][i-1], d[0][i-2]) + arr[1][i];
        }
        cout << max(d[0][n], d[1][n]) << "\n";
    }
    return 0;
}
