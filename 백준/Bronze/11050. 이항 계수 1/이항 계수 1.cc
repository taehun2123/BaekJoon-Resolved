#include <bits/stdc++.h>
using namespace std;
int Factorial(int num){
    if(num == 0 || num == 1) return 1;
    else
        return num * Factorial(num-1);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    cout << Factorial(n)/ (Factorial(k) * Factorial(n-k));
}
