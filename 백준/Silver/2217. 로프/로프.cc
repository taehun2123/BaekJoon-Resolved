#include <bits/stdc++.h>
using namespace std;
int n, ans;
int w[100002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++) cin >> w[i];
    sort(w, w+n);
    for(int i = 1; i<=n; i++){
        ans = max(ans, w[n-i]*i);
    }
    cout << ans;
    return 0;
}
