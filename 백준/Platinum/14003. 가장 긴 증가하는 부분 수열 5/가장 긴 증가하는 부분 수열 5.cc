#include <bits/stdc++.h>
using namespace std;
vector<int> v1, v2;
int n;
int idx[1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v1.push_back(t);
    }

    vector<int> lis, lis_idx, parent(n, -1); // lis에서 각 숫자가 위치한 v1의 인덱스를 저장

    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(lis.begin(), lis.end(), v1[i]) - lis.begin();

        if (pos < lis.size()) {
            lis[pos] = v1[i];
        } else {
            lis.push_back(v1[i]);
        }

        if (pos > 0) {
            parent[i] = lis_idx[pos - 1];
        }
        if (pos < lis_idx.size()) {
            lis_idx[pos] = i;
        } else {
            lis_idx.push_back(i);
        }
    }

    cout << lis.size() << "\n";

    // LIS 역추적
    vector<int> fLis;
    for (int i = lis_idx.back(); i != -1; i = parent[i]) {
        fLis.push_back(v1[i]);
    }
    reverse(fLis.begin(), fLis.end());

    for (auto &val : fLis) {
        cout << val << " ";
    }

    return 0;
}
