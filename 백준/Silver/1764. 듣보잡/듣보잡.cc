#include <bits/stdc++.h>
using namespace std;
set<string> ear;
set<string> result;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    string in;
    for(int i = 0; i<n; i++){
        cin >> in;
        ear.insert(in);
    }
    for(int i = 0; i<m; i++) {
        cin >> in;
        if(ear.count(in)) result.insert(in);
    }

    cout << result.size() << "\n";
    for(auto i:result){
        cout << i << "\n";
    }
    return 0;
}
