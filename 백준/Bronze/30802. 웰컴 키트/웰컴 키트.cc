#include <bits/stdc++.h>
using namespace std;
int siz[6];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,t,p;
    cin >> n;
    for(int i = 0; i<6; i++){
        cin >> siz[i];
    }
    cin >> t >> p;
    int cnt = 0;
    for(int i = 0; i < 6; i++) {
        cnt += siz[i] / t;
        if(siz[i] % t != 0) {
            cnt++;
        }
    }
    cout << cnt << "\n" << n/p << " " << n%p;
}
