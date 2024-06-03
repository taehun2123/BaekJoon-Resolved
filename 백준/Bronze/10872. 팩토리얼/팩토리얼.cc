#include <bits/stdc++.h>
using namespace std;
int Factorial(int value){
    int r = 1;
    for(int i = 1; i<=value; i++){
        r = r * i;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, sum = 1;
    cin >> x;

    cout << Factorial(x);
}
