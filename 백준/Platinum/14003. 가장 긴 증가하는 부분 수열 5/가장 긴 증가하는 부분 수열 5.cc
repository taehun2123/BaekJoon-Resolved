#include <bits/stdc++.h>
using namespace std;
vector<int> v1;
vector<int> lis, lis_idx, ans; // lis: stores LIS elements, lis_idx: indexes in v1, ans: stores the actual LIS
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v1.push_back(t);
    }

    lis.push_back(v1[0]);
    lis_idx.push_back(0);

    for (int i = 1; i < n; i++) {
        int cur = v1[i];

        if(lis.back() < cur){
            lis_idx.push_back(lis.size());
            lis.push_back(cur);
        }
        else {
            auto iter = lower_bound(lis.begin(), lis.end(), cur);
            *iter = cur;
            lis_idx.push_back(iter - lis.begin());
        }
    }

    cout << lis.size() << "\n";

    int cur = lis.size() - 1;
    for(int i = lis_idx.size() - 1; i >= 0; i--){
        if(cur == lis_idx[i]) {
            ans.push_back(v1[i]);
            cur--;
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }

    return 0;
}
