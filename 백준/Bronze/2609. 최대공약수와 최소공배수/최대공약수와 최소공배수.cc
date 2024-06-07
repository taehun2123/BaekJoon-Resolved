#include <bits/stdc++.h>
using namespace std;
// 최대 공약수 구하기: 유클리드 호제법
int divide(int A, int B) {
    if (A % B == 0)
        return B;
    else
        return divide(B, A % B);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin >> a >> b;
    if(a < b){
        int temp = a;
        a = b;
        b = temp;
    }
    int dd = divide(a, b);
    cout << dd << "\n";
    cout << (a*b)/dd;
    return 0;
}
