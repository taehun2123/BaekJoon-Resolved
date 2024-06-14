#include <bits/stdc++.h>
using namespace std;

long long gob(long long A, long long B, long long C){
    if(B == 1) return A%C;
    long long value = gob(A, B/2, C); // K승이 계산이 가능하면 2K승도 계산 가능하다 -> K/2승도 계산 가능하다.
    value = value * value % C; // B/2승의 값 * B/2승의 값 = B승의 값 A^N * A^N = A^2N
    if(B%2 == 0) return value; // 짝수인 경우, 정상적인 계산이 동작됨,
    return value * A % C; //  B가 7이라고 가정하면 B/2는 3이므로 1거듭 제곱이 부족함 따라서 A를 한 번 더 곱함
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int A, B, C;
    cin >> A >> B >> C;
    cout << gob(A, B, C);


    return 0;
}
