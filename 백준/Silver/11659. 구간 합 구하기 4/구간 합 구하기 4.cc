#include <bits/stdc++.h>
using namespace std;
int n, m;
int arrN[100002];
int d[100002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> arrN[i];
        d[i] = d[i-1] + arrN[i];
    }
    while(m--){
        int i, j;
        cin >> i >> j;
        cout << d[j] - d[i-1] << "\n";
    }
    return 0;
}
