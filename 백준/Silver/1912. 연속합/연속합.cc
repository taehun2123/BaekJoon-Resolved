#include <bits/stdc++.h>
using namespace std;
int arr[100002];
int d[100002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
        d[i] = max(0, d[i-1]) + arr[i];
    }
    cout << *max_element(d+1, d+n+1);
    return 0;
}
