#include <bits/stdc++.h>
using namespace std;

void check(int x){
    if (x % 3 == 0) {
        if (x % 5 == 0) {
            cout << "FizzBuzz";
        } else {
            cout << "Fizz";
        }
    } else if (x % 5 == 0) {
        cout << "Buzz";
    } else {
        cout << x;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b, c;
    cin >> a >> b >> c;
    if (c[0]-'0' >= 0 && c[0]-'0' <= 9) {
        int x = stoi(c) + 1;
        check(x);
    } else if (b[0]-'0' >= 0 && b[0]-'0' <= 9) {
        int x = stoi(b) + 2;
        check(x);
    } else if (a[0]-'0' >= 0 && a[0]-'0' <= 9) {
        int x = stoi(a) + 3;
        check(x);
    }
    return 0;
}
