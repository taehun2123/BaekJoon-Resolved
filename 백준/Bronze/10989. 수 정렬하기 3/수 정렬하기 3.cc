#include <bits/stdc++.h>
using namespace std;
int table[10001];
int n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i<=n; i++){
        int a;
        cin >> a;
        table[a]++;
    }
    for(int i = 1; i<=10000; i++){
        while(table[i]){
            cout << i << "\n";
            table[i]--;
        }
    }
    return 0;
}
