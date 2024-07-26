#include <bits/stdc++.h>
using namespace std;
int n;
long long d[100];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[1] = 1;
    d[2] = 1;
    for(int i = 3; i<=n; i++){
        for(int j = i-2; j>0; j--){
            d[i] += d[j];
        }
        d[i]++;
    }

    cout << d[n];
    return 0;
}
