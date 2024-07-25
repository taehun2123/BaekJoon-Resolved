#include <bits/stdc++.h>
using namespace std;
int n, ans;
int a[55], b[55];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    sort(a, a+n);
    sort(b, b+n);
    for(int i = 0; i<n; i++){
        ans += a[i] * b[n-1-i];
    }
    cout << ans;
    return 0;
}
