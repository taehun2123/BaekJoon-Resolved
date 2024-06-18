#include <bits/stdc++.h>
using namespace std;
string input, ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> input;
    for(auto ch: input){
        ans += toupper(ch);
    }
    cout << ans;

}
