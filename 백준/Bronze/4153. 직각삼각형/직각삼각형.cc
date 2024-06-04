#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);
    while(1){
        int a,b,c;
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0) break;
        if(((a*a) + (b*b) == (c*c)) || ((b*b) + (c*c) == (a*a)) || ((a*a) + (c*c) == (b*b)))
            cout << "right" << "\n";
        else
            cout << "wrong" << "\n";
    }
}
