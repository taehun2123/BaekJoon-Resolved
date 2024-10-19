#include <bits/stdc++.h>
using namespace std;
vector<long long> li;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++){
        int a;
        cin >> a;
        li.push_back(a);
    }

    for(int i = n-2; i>0; i--){
        if(i==1){
            li[0]--;
            li[n-1]--;
        }
        else {
            if(li[0] > li[n-1]) li[0]--;
            else li[n-1]--;
        }
    }
    long long ans = max(li[0], li[n-1]);
    cout << ans;

    return 0;
}
