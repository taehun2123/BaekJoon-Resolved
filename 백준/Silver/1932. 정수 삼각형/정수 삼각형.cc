#include <bits/stdc++.h>
using namespace std;
int n;
int a[505][505];
int d[505][505];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<i; j++){
            cin >> a[i][j];
        }
    }

    d[0][0] = 0;
    d[1][0] = a[1][0];

    for(int i = 2; i<=n; i++){
        for(int j=0; j<i; j++){
            d[i][j] += max(d[i-1][j-1], d[i-1][j]) + a[i][j];
        }
    }
    int mx = d[n][0];
    for(int i = 1; i<=n; i++){
        if(mx < d[n][i]){
            mx = d[n][i];
        }
    }
    cout << mx;
    return 0;
}
