#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> box;
bool comp(const pair<int,int> &v1, const pair<int,int>&v2){
    if(v1.first == v2.first)
            return v1.second < v2.second;
    return v1.first < v2.first;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);
    int n;
    cin >> n;
    while(n--){
        int x,y;
        cin >> x >> y;
        box.emplace_back(x, y);
    }
    sort(box.begin(),box.end(), comp);
    for(auto &i : box){
        cout << i.first << " " << i.second << "\n";
    }
}
