#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
bool comp(const pair<int, int> &p1,const pair<int, int> &p2){
    if(p1.second==p2.second){
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        int in;
        cin >> in;
        sum += in;
        arr.push_back(in);
    }

    cout << (int)floor((sum/n) + 0.5) << "\n"; // 산술 평균
    sort(arr.begin(), arr.end());
    cout << arr.at(n/2) << "\n"; // 중앙값;
    vector<pair<int,int>> st;
    for(int & i : arr){
        if(!st.empty() && st.back().first == i){
            st.back().second++;
        } else {
            st.emplace_back(i, 1);
        }
    }

    sort(st.begin(), st.end(), comp);
    if(st[0].second == st[1].second) cout << st[1].first << "\n";
    else cout << st[0].first << "\n";

    cout << arr.back() - arr.front(); //범위
}
