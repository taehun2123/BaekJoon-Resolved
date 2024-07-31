#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, numIdx = 1;
    cin >> T;
    while(T--){
        vector<int> v1;
        vector<int> lis, lis_idx, ans;
        int n, k;

        cin >> n >> k;
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
        cout << "Case #" << numIdx << "\n";
        if(lis.size() >= k) cout << 1 << "\n";
        else cout << 0 << "\n";
        numIdx++;
    }

    return 0;
}
