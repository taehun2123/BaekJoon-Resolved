#include <bits/stdc++.h>
using namespace std;

int func(int n, int r, int c){
    if(n == 0) return 0;
    int half = 1<<(n-1); //1 << (n-1)은 2^(n-1)과 동일
    //n = 1일 때: half = 1 << (1-1) = 1 << 0 = 1
    //n = 2일 때: half = 1 << (2-1) = 1 << 1 = 2
    //n = 3일 때: half = 1 << (3-1) = 1 << 2 = 4
    //n = 4일 때: half = 1 << (4-1) = 1 << 3 = 8
    if(r < half && c < half) return func(n-1, r, c); //첫 번째 사분면일 때(좌상단)
    //두 번째 사분면일 때, 첫 번째 사분면의 모든 위치를 지나야 하므로 half*half를 더해주고,
    //재귀적으로 나머지 부분을 탐색
    if(r < half && c >= half) return half*half + func(n-1, r, c-half);
    if(r >= half && c < half) return 2*half*half + func(n-1, r-half, c);
    return 3*half*half + func(n-1, r-half, c-half);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r, c;
    cin >> n >> r >> c;
    cout << func(n, r, c);
}
