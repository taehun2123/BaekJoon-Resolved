#include <bits/stdc++.h>
const int MAX = 1e9+5;
using namespace std;
int n, s, tot;
long long arr[100003];
int ans1 = MAX;
int ans2 = MAX;
// 투포인터
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    int st = 0;
    int en = n-1;
    while(st < en){
        if(abs(ans1+ans2) > abs(arr[st]+arr[en])){
            ans1 = arr[st];
            ans2 = arr[en];
        }
        if(abs(arr[st] + arr[en-1]) <= abs(arr[st+1] + arr[en])) en--;
        else st++;
    }
    cout << ans1 + ans2;
    return 0;
}
