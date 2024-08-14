#include <bits/stdc++.h>
using namespace std;

int arr[1500001];
int v[1500001];
int d[1500001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> arr[i] >> v[i];
    }

    for(int i = 1; i <= n; i++){
        if (d[i] < d[i-1]) {
            d[i] = d[i-1];
        }
        d[i + arr[i] - 1] = max(d[i + arr[i] - 1], d[i - 1] + v[i]);
    }

    cout << d[n];
    return 0;
}
