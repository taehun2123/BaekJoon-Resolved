#include <bits/stdc++.h>
using namespace std;
vector<int> v1, v2;
int idx[100002];
int n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        int t; cin >> t;
        v1.push_back(t);
        idx[t] = i;
    }

    for(int i = 0; i<n; i++){
        int t; cin >> t;
        v2.push_back(idx[t]);
    }

    vector<int> lis;
    for(auto &i:v2){
        if(lis.empty() || lis.back() < i) lis.push_back(i);
        else lis[lower_bound(lis.begin(), lis.end(), i) - lis.begin()] = i;
    }

    cout << lis.size();
    return 0;
}
