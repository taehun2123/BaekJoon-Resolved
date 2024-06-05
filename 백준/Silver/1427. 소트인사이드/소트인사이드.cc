#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int comp(const int &v1, const int &v2){
    return v1 > v2;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int su;
    cin >> su;
    string s = to_string(su);
    for(auto c: s)
        arr.push_back(c - '0');
    stable_sort(arr.begin(), arr.end(), comp);
    for(auto i: arr)
        cout << i;
}
