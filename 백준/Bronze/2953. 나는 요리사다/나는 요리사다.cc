#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> ranking;
int comp(const pair<int,int> &v1, const pair<int,int> &v2){
    return v1.second > v2.second;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i<5; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        ranking.emplace_back(i+1, a+b+c+d);
    }
    sort(ranking.begin(), ranking.end(), comp);
    for(auto i : ranking){
        cout << i.first << " " << i.second;
        break;
    }

    return 0;
}
