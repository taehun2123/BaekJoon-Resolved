#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    while(cin >> a >> b >> c && (a || b || c)) {
        int mx = max({a, b, c});
        int mn = min({a, b, c});
        int md = a + b + c - mx - mn;

        if(mx >= md + mn) {
            cout << "Invalid\n";
        }
        else if(a == b && b == c) {
            cout << "Equilateral\n";
        }
        else if(a == b || b == c || c == a) {
            cout << "Isosceles\n";
        }
        else {
            cout << "Scalene\n";
        }
    }
}