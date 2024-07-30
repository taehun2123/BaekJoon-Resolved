#include <bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;
int board[105][105];
int vis[105];
bool flag;
struct pos{
    int x;
    int y;
};
pos saved[102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        /** 초기화 **/
        for(int i = 0; i<n+2; i++)
            for(int j = 0; j<n+2; j++)
                board[i][j] = 0;
        flag = false;
        for(int i = 0; i<n+2; i++) vis[i] = 0;
        /** **/


        for(int i = 0; i< n+2; i++){ // 편의점 개수의 + 2만큼의 좌표값이 들어옴
            cin >> saved[i].x >> saved[i].y;
        }

        for(int i = 0; i<n+2; i++){
            for(int j = i+1; j<n+2; j++){
                int nx = saved[i].x - saved[j].x; // 현재와 다음 좌표를 '제'한 값을 nx
                int ny = saved[i].y - saved[j].y;
                if(nx < 0) nx *= -1; // '제'한 값이 음수면 양수로 바꿈
                if(ny < 0) ny *= -1;
                if(nx + ny <= 1000){ // 양수인 두 좌표의 합한 결과가 50*20 = 1000 보다 작다면
                    board[i][j] = 1; // 갈 수 있다는 표시
                    board[j][i] = 1;
                }
            }
        }


        //큐 시작
        queue<int> Q;
        Q.push(0); //시작 점은 0
        vis[0] = 1;
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            if(cur == n+1) { // 현재 지점이 n+1이면 도착했다는 뜻
                flag = true;
                break;
            }

            for(int i = 0; i<n+2; i++){
                if(vis[i] == 0 && board[cur][i] == 1){ // 방문 X, board 칸이 1일 때만 접근 가능
                    vis[i] = 1;
                    Q.push(i);
                }
            }
        }

        if(flag) cout << "happy" << "\n";
        else cout << "sad" << "\n";

    }
    return 0;
}
