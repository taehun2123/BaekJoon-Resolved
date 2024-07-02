#include <bits/stdc++.h>
using namespace std;
int n;
int r[1002], b[1002], g[1002];
int paint[1002][3];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> r[i] >> g[i] >> b[i];
    paint[1][0] = r[1]; //첫 번째 집이 빨강일 때
    paint[1][1] = g[1]; // 첫 번째 집이 초록일 때
    paint[1][2] = b[1]; // 첫 번째 집이 파랑일 때
    for(int i = 2; i<=n; i++){
        paint[i][0] = min(paint[i-1][1], paint[i-1][2]) + r[i]; //i번째 집이 빨강일때 최소값
        paint[i][1] = min(paint[i-1][0], paint[i-1][2]) + g[i];
        paint[i][2] = min(paint[i-1][0], paint[i-1][1]) + b[i];
    }
    cout << min({paint[n][0], paint[n][1], paint[n][2]});
    return 0;
}
