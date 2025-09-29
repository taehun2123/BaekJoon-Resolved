#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<bool> isPrime(1000001, true);
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    isPrime[1] = false;
    for(int i = 2; i*i <= m; i++){
        if(!isPrime[i]) continue;
        for(int j = i*i; j<=m; j+=i){
            isPrime[j] = false;
        }
    }
    for(int i = n; i<=m; i++){
        if(isPrime[i]) cout << i << "\n";
    }

    return 0;
}
