#include <bits/stdc++.h>
using namespace std;
bool arr[2000001];
int a[1000001];
int n, x, cnt;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    cin >> x;
    for(int i = 0; i<n; i++){
        if(x-a[i] > 0 && arr[x-a[i]]) cnt++;
        arr[a[i]] = 1;
    }

    cout << cnt;

    return 0;
}
