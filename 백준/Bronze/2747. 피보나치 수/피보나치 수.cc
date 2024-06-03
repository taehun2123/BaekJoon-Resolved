#include <iostream>
using namespace std;

int fibo(int x) {
    int f = 0;
    int a = 0;
    int b = 1;
    if(x == 1) return 1;
    for(int i = 1; i<x; i++){
        f = a+b;
        a = b;
        b = f;
    }
    return f;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin >> x;
    cout << fibo(x);
    return 0;
}
