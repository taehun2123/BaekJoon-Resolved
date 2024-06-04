#include <bits/stdc++.h>
using namespace std;
vector<int> box;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        int su;
        cin >> su;
        box.push_back(su);
    }
    sort(box.begin(),box.end());
    box.erase(unique(box.begin(), box.end()),box.end());
    for(auto &i : box){
        cout << i << "\n";
    }
}
