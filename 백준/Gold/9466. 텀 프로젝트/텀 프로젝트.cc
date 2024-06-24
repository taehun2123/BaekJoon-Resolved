#include <bits/stdc++.h>
using namespace std;
int board[100002];
int vis[100002];
int T,n;
void run(int x){
    int cur = x; //예 cur = 1
    while(true){
        vis[cur] = x; // vis[1] = 1;
        cur = board[cur]; // cur = board[1] == 3이라고 가정;

        //이번 방문에서 지나간 학생에 도달했을 경우
        if(vis[cur] == x){ //vis[3] == 1
            while(vis[cur] != -1){ //vis[3]이 -1이 아닌 것이 true 조건 - 사이클 검사
                vis[cur] = -1; // vis[3] = -1
                cur = board[cur]; //board[cur] == 3임 cur == 3 - vis[3]만 -1로 변함(자기 자신 사이클)
            }
            return;
        }
        //이전 방문에서 지나간 학생에 도달했을 경우
        else if(vis[cur] != 0) return;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        fill(vis+1, vis+n+1, 0); //방문 배열 초기화
        for(int i = 1; i<=n; i++){
            cin >> board[i];
        }
        for(int i = 1; i<=n; i++){
            if(vis[i] == 0) run(i); //사이클 확인
        }
        int cnt = 0;
        for(int i = 1; i<=n; i++){
            if(vis[i] != -1) cnt++; //vis[i]값이 -1이 아니면 사이클이 아닌 것 = 팀에 속하지 못함
        }
        cout << cnt << "\n";
    }

    return 0;
}
