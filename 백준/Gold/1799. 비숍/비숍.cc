#include <bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;
/**
 * 비숍의 경우, 검은색 칸과 흰색 칸은 각자의 비숍을 놓을 수 있는 자리에 영향을 주지 않는다.
 * 검은색 칸은 검은색 칸끼리만 영향을 받고 흰색 칸은 흰색 칸끼리만 영향을 받는다.
 * 따라서 검은색 칸과 흰색 칸, 두 가지의 경우로 나누어 풀면 시간을 줄일 수 있다.
 * 최대 10*10 만큼 탐색해야 하는 것을 5*5 두 번으로 탐색 가능하다.
 */
// 체스판의 색깔((r,c)에 대해 r+c가 짝수일 경우 0에 대응, 홀수일 경우 1에 대응)에 따라 분리해서 계산
int n;
vector<pii> board[2][20];//색깔 i에 대해 \ 방향 대각선에 포함되는 칸들을 저장함
bool vis[2][20];
int ans[2];

void tracking(int idx, int cnt, int color){
     if(idx == 2 * n){
         ans[color] = max(ans[color], cnt);
         return;
     }
     for(auto v : board[color][idx]) {
         int x, y;
         tie(x, y) = v;
         if (vis[color][x + y]) continue; // 이미 방문된 위치면 넘김
         vis[color][x + y] = true;
         tracking(idx + 1, cnt + 1, color); // 개수와 다음 인덱스 + 1
         vis[color][x + y] = false;
     }
     tracking(idx+1, cnt, color); //비숍을 놓지 않았을 때
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int picked;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> picked;
            if(picked){ // 1일때(놓을 수 있는 공간들에 대해서)
                board[(i+j+1)%2][i-j+n-1].push_back({i,j}); // 흰색, 검은색 구분, \방향 대각선에 포함되는 칸들 저장
            }
        }
    }
    tracking(0,0,0); // 홀수(0에 대응한 값)
    tracking(0,0,1); // 짝수(1에 대응한 값)
    cout << ans[0] + ans[1];
    return 0;
}
