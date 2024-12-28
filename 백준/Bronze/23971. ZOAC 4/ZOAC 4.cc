#include <bits/stdc++.h>
using namespace std;
double H, W, N, M;
// W개씩 H행에 걸쳐 있을 때,
// 모든 참가자는 세로로 N칸 또는 가로로 M칸 이상 비우고 앉아야 한다.
// 즉, 다른 모든 참가자와 세로줄 번호의 차가 N보다 크거나 가로줄 번호의 차가 M보다 큰 곳에만 앉을 수 있다.
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> H >> W >> N >> M; // 5 4 1 1 -> 4개씩 5행에 걸처 있을 떄 세로 1칸 또는 가로 1칸 이상 비우고 앉아야한다.
    cout << (int)(ceil(H/(N+1))*ceil(W/(M+1)));
    return 0;
}
