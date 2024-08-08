#include <bits/stdc++.h>
const int MAX = 0x7fffffff;
using namespace std;
int n, s, tot;
int arr[100003];
int mn = MAX;
// 투포인터
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    int en = 0;
    tot = arr[0];
    for(int st = 0; st<n; st++){
        while(en < n && tot < s) if(en != n) tot += arr[++en];
        if(en == n) break;
        mn = min(mn, en-st+1);
        tot -= arr[st];
    }
    if(mn == MAX) mn = 0;
    cout << mn;
    return 0;
}
