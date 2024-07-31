#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v1;
int arr[10002];
int n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        int t, idx; cin >> idx >> t;
        v1.push_back({idx, t});
    }

    sort(v1.begin(), v1.end());


    //LIS O(NlogN)
    vector<int> lis;
    for (auto &i: v1){
        if (lis.size() == 0 || lis.back() < i.second) lis.push_back(i.second);
        else lis[lower_bound(lis.begin(), lis.end(), i.second) - lis.begin()] = i.second;
    }


    cout << n-lis.size();
    return 0;
}
