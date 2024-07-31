#include <bits/stdc++.h>
using namespace std;
vector<int> v1, v2;
int n;
int idx[40001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        int t; cin >> t;
        v1.push_back(t);
    }

    vector<int> lis;
    for (auto &i: v1){
        if (lis.size() == 0 || lis.back() < i) lis.push_back(i);
        else lis[lower_bound(lis.begin(), lis.end(), i) - lis.begin()] = i;
    }

    cout << lis.size();
    return 0;
}
