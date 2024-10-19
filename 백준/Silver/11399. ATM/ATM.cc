#include <bits/stdc++.h>
using namespace std;
int li[1002], ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i<n; i++) cin >> li[i];
    sort(li, li+n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<=i; j++){
            ans += li[j];
        }
    }
    cout << ans;
    return 0;
}
