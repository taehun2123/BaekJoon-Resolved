#include <bits/stdc++.h>
using namespace std;
vector<pair<int,string>> box;

bool ucomp(const pair<int,string> &v1, const pair<int,string> &v2){
    return v1.second == v2.second;
}

bool comp(const pair<int,string> &v1, const pair<int,string> &v2){
    if(v1.first == v2.first){
        return v1.second<v2.second;
    }
    return v1.first < v2.first;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        string word;
        cin >> word;
        box.emplace_back(word.size(), word);
    }
    sort(box.begin(),box.end(),comp);
    box.erase(unique(box.begin(), box.end(), ucomp),box.end());
    for(auto &i : box){
        cout << i.second << "\n";
    }
}
