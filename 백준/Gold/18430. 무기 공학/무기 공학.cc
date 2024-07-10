#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int board[6][6];
bool used[6][6];
int case_1(int x, int y){
    /**
     * ㅁㅁ
     * ㅁ
     */
    return board[x][y]*2 + board[x+1][y] + board[x][y+1];
}

int case_2(int x, int y){
    /**
     * ㅁ
     * ㅁㅁ
     */
    return board[x][y]*2 + board[x-1][y] + board[x][y+1];
}

int case_3(int x, int y){
    /**
     *  ㅁ
     * ㅁㅁ
     */
    return board[x][y]*2 + board[x-1][y] + board[x][y-1];
}

int case_4(int x, int y){
    /**
     * ㅁㅁ
     *  ㅁ
     */
    return board[x][y]*2 + board[x+1][y] + board[x][y-1];
}

bool isBound(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m && !used[x][y];
}



void creative(int x, int y, int po){
    if(y == m){
        y = 0;
        x++;
    }

    if(x == n){
        ans = max(ans, po);
        return;
    }


    if(!used[x][y]){
        int curPo = 0;
        if(isBound(x, y+1) && isBound(x+1, y)){
            used[x][y] = 1;
            used[x+1][y] = 1;
            used[x][y+1] = 1;
            curPo = po+case_1(x, y);
            creative(x, y+1, curPo);
            used[x][y] = 0;
            used[x+1][y] = 0;
            used[x][y+1] = 0;
        }
        if(isBound(x, y+1) && isBound(x-1, y)){
            used[x][y] = 1;
            used[x-1][y] = 1;
            used[x][y+1] = 1;
            curPo = po+case_2(x, y);
            creative(x, y+1, curPo);
            used[x][y] = 0;
            used[x-1][y] = 0;
            used[x][y+1] = 0;
        }
        if(isBound(x, y-1) && isBound(x-1, y)){
            used[x][y] = 1;
            used[x-1][y] = 1;
            used[x][y-1] = 1;
            curPo = po+case_3(x, y);
            creative(x, y+1, curPo);
            used[x][y] = 0;
            used[x-1][y] = 0;
            used[x][y-1] = 0;
        }
        if(isBound(x, y-1) && isBound(x+1, y)){
            used[x][y] = 1;
            used[x+1][y] = 1;
            used[x][y-1] = 1;
            curPo = po+case_4(x, y);
            creative(x, y+1, curPo);
            used[x][y] = 0;
            used[x+1][y] = 0;
            used[x][y-1] = 0;
        }
    }
    creative(x, y+1, po);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    if(n <= 1 || m <= 1){
        cout << 0;
        return 0;
    }

    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            cin >> board[i][j];

    creative(0, 0, 0);
    cout << ans;
    return 0;
}
