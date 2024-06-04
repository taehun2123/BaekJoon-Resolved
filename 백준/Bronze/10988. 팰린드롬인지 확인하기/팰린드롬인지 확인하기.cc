#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<char> box;
    string input;
    cin >> input;
    for(auto c: input)
        box.push_back(c);

    bool flag = false;
    for (int i = 0; i < box.size()/2; i++) {
        if (box[i] != box[(box.size()-1) - i]) {
            cout << 0;
            flag = true;
            break;
        }
    }
    if(!flag)
        cout << 1;
}
