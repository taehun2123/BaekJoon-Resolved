#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        int input;
        cin >> input;
        string s = to_string(input);
        if(input == 0) break;
        vector<char> box;
        for(auto c : s)
            box.push_back(c);

        bool flag = false;
        for(int i = 0; i<box.size()/2; i++){
            if(box[i] != box[(box.size()-1)-i]){
                cout << "no" << "\n";
                flag = true;
                break;
            }
        }
        if(!flag)
            cout << "yes" << "\n";
    }
}
