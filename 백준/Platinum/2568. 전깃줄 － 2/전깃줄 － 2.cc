#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v1;
vector<int> lis, lis_idx, ans; // lis에서 각 숫자가 위치한 v1의 인덱스를 저장
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int idx, t;
        cin >> idx >> t;
        v1.push_back({idx, t});
    }

    sort(v1.begin(), v1.end());

    lis.push_back(v1[0].second);
    lis_idx.push_back(0);

    for (int i = 1; i < n; i++) {
        auto cur = v1[i].second;

        if(lis.back() < cur){ //자르지 않아도 되는 선
            lis_idx.push_back(lis.size());
            lis.push_back(cur);
        }
        
        else { //잘라야 하는 선
            auto iter = lower_bound(lis.begin(), lis.end(), cur);
            *iter = cur;
            lis_idx.push_back(iter - lis.begin());
        }
    }

    cout << n-lis.size() << "\n";

    // LIS 역추적
    auto cur = lis.size() -1;
    for(int i = lis_idx.size()-1; i>=0; i--){
        if(cur == lis_idx[i]) cur--;
        else ans.push_back(v1[i].first);
    }

    for (int i = ans.size()-1; i>=0; i--) {
        cout << ans[i] << "\n";
    }

    return 0;
}
