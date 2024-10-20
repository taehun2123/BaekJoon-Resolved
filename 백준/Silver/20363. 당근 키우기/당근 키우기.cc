#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long x, y;
    cin >> x >> y;

    long long mini = min(x, y);
    cout << x+y+(mini/10);
    return 0;
}
