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

    vector<int> lis, parent(n, -1);
    vector<int> lis_indices;  // lis에서 각 숫자가 위치한 v1의 인덱스를 저장
    int lis_end_index = -1;

    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(lis.begin(), lis.end(), v1[i]) - lis.begin();

        if (pos < lis.size()) {
            lis[pos] = v1[i];
        } else {
            lis.push_back(v1[i]);
        }

        if (pos > 0) {
            parent[i] = lis_indices[pos - 1];
        }
        if (pos < lis_indices.size()) {
            lis_indices[pos] = i;
        } else {
            lis_indices.push_back(i);
        }
        lis_end_index = lis_indices.back();
    }

    cout << lis.size() << "\n";

    // LIS 역추적
    vector<int> actualLis;
    for (int i = lis_end_index; i != -1; i = parent[i]) {
        actualLis.push_back(v1[i]);
    }
    reverse(actualLis.begin(), actualLis.end());

    for (auto &val : actualLis) {
        cout << val << " ";
    }

    return 0;
}
