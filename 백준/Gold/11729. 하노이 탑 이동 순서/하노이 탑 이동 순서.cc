#include <bits/stdc++.h>
using namespace std;
void hanoi(int start, int end, int n){
    if(n == 1){
        cout << start << ' ' << end << "\n";
        return;
    }
    hanoi(start, 6-start-end, n-1); // n-1 원판을 기둥 a에서 기둥 6-a-b로 옮긴다.
    cout << start << ' ' << end << '\n'; // n 원판을 기둥 a에서 b로 옮긴다.
    hanoi(6-start-end, end, n-1); // n-1원판을 기동 6-a-b에서 기동 b로 옮긴다.
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int K;
    cin >> K;
    cout << (1<<K)-1 << "\n"; //비트 연산 - 왼쪽으로 1비트 = K^2-1
    hanoi(1, 3, K);
    return 0;
}
