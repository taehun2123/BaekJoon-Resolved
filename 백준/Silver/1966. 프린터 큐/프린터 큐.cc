#include <bits/stdc++.h>
using namespace std;
queue<pair<int,int>> que;
int cntBox[9];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, t, index, value;
    cin >> t;
    while(t--){
        cin >> n >> m;
        fill(cntBox, cntBox + 9, 0);
        que = queue<pair<int,int>>();
        for(int i = 0; i < n; i++){
            int val;
            cin >> val;
            cntBox[val-1]++;
            que.emplace(i, val);
        }
        int cnt = 1;
        bool flag = false;
        for(int i = 8; i >= 0; i--){
            while(cntBox[i] > 0){
                while(que.front().second != i + 1){
                    index = que.front().first;
                    value = que.front().second;
                    que.pop();
                    que.emplace(index, value);
                }
                if(que.front().first == m){
                    flag = true;
                    break;
                } else {
                    cnt++;
                    que.pop();
                    cntBox[i]--;
                }
            }
            if(flag){
                break;
            }
        }
        cout << cnt << "\n";
    }
}
