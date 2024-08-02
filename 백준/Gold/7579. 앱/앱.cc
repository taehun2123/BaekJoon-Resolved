#include <bits/stdc++.h>
using namespace std;
int N, M;
int mem[102]; // 차지하는 메모리 -- mem[i+..n] = M
int c[102]; // 비용 - 최소
int dp[10002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M; // N 현재 앱 개수, M 삭제 요구 메모리
    for(int i = 0; i<N; i++) cin >> mem[i];
    for(int i = 0; i<N; i++) cin >> c[i];

    for(int i = 0; i<N; i++){
        for(int j = 10001; j>=c[i]; j--){ // 비용 관점 dp
            dp[j] = max(dp[j], dp[j-c[i]]+mem[i]);
        }
    }
    for(int i = 0; i<10002; i++){
        if(dp[i] >= M){
            cout << i;
            return 0;
        }
    }
    return 0;
}
