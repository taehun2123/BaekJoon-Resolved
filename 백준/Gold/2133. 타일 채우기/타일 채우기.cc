#include <bits/stdc++.h>
using namespace std;
int d[3000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if(n % 2 == 1){
        cout << 0;
        return 0;
    }
    d[0] = 1;
    d[1] = 0;
    d[2] = 3;

    for(int i = 4; i<=n; i+=2){
        d[i] = d[i-2]*d[2];
        for(int j = i-4; j>=0; j-=2){
            d[i] += d[j]*2;
        }
    }
    cout << d[n];
    return 0;
}
