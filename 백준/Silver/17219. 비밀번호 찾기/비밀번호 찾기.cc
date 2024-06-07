#include <bits/stdc++.h>
using namespace std;
map<string, string> sites;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while(n--){
        string add;
        string pw;
        cin >> add >> pw;
        sites[add] = pw;
    }
    while(m--){
        string add;
        cin >> add;
        cout << sites[add] << "\n";
    }
    return 0;
}
