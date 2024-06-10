#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    string a;
    for(int i = 0; i<n; i++){
        cin >> a;
        reverse(a.begin(), a.end());
        cout << a << "\n";
    }
}