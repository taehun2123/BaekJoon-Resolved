#include <bits/stdc++.h>
using namespace std;

map<string, int> inList;

bool comp(const pair<string, int> &v1, const pair<string, int> &v2) {
    return v1.first > v2.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        string user, log;
        cin >> user >> log;
        if(log == "enter"){
            inList[user]++;
        } else {
            inList[user]--;
        }
    }

    vector<pair<string, int>> vec(inList.begin(), inList.end());
    sort(vec.begin(), vec.end(), comp);
    for(auto &i: vec){
        if(i.second == 1){
            cout << i.first << "\n";
        }
    }
}
