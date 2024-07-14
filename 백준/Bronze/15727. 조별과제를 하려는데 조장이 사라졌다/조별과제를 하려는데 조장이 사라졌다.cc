#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int l, sum = 0, i;
    cin >> l;
    sum = l/5;
    if(l%5!=0) sum++;
    cout << sum;
    return 0;
}
