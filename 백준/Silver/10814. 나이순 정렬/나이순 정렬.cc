#include <bits/stdc++.h>
using namespace std;
vector<pair<int,string>> box;
bool comp(const pair<int,string>&v1, const pair<int,string>&v2){
    return v1.first < v2.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        int age;
        string name;
        cin >> age >> name;
        box.emplace_back(age,name);
    }
    stable_sort(box.begin(), box.end(),comp); //같으면 그대로 들어감.
    for(auto & i : box){
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}
