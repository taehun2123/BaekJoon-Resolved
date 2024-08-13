#include <bits/stdc++.h>
using namespace std;

int arr[1002];
int v[1002];
int d[1002];
vector<pair<int,int>> ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> arr[i] >> v[i];
    }

    for(int i = n; i >= 1; i--){
        if (i + arr[i] <= n+1) {
            d[i] = max(d[i+arr[i]] + v[i], d[i+1]);
        } else {
            d[i] = d[i+1];
        }
    }

    cout << *max_element(d + 1, d + n + 1);
    return 0;
}
