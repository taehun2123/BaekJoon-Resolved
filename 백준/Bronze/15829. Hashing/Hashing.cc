#include <bits/stdc++.h>
using namespace std;
vector<long long> arrs;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int length;
    string s;
    long long mod = 1234567891;
    cin >> length >> s;
    for(auto c: s){
        arrs.push_back((c - 'a')+1);
    }
    long long sum = 0;
    for(int i = 0; i<length; i++){
        for(int k = 0; k<i; k++){
            arrs[i] *= 31;
            arrs[i] %= mod;
        }
        sum += arrs[i];
    }

    cout << sum % mod;
    return 0;
}
