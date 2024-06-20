#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    stack<int> S;
    int cnt = 1;
    string s;
    while(n--){
        int a;
        cin >> a;
        while(cnt <= a){
            S.push(cnt++);
            s += "+\n";
        }
        if(S.top() != a){
            cout << "NO\n";
            return 0;
        }
        S.pop();
        s += "-\n";
    }
    cout << s;
}
