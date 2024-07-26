#include <bits/stdc++.h>
using namespace std;
int n;
int a[1002];
int d[1002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++) {
        cin >> a[i];
        d[i] = a[i];
    }
    for(int i = 0; i<n; i++)
        for(int j = 0; j<i; j++)
            if(a[j] < a[i]) d[i] = max(d[i], d[j]+a[i]);

    cout << *max_element(d, d+n);
    return 0;
}
