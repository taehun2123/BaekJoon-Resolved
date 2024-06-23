#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> in;
vector<string> out;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, cnt = 0;
    cin >> n;
    for(int i = 0; i<n; i++){
        string inp;
        cin >> inp;
        in.insert({inp, i});
    }
    for(int i = 0; i<n; i++){
        string outp;
        cin >> outp;
        out.push_back(outp);
    }

    for(int i = 0; i<out.size(); i++){
        for(int j = i+1; j<out.size(); j++){
            if(in[out[i]] > in[out[j]]){
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
    return 0;
}
