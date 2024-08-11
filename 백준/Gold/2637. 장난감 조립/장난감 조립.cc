#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n, m;

vector<pii> req[102];
int cnt[102], deg[102];
bool isbase[102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(isbase, isbase + 102, 1);
    cin >> n >> m;
    for(int i = 1; i<=m; i++){
        int x, y, k;
        cin >> x >> y >> k;
        isbase[x] = 0; // X는 중간부품이나 최상위 부품 - 최하위 부품이 아님을 표시
        req[x].push_back({y, k}); // x를 만들기 위해서는 y가 k개가 필요함
        deg[y]++;
    }

    queue<int> q;
    q.push(n);
    cnt[n] = 1;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto [nxt, cn] : req[cur]){
            cnt[nxt] += cn * cnt[cur];
            if(--deg[nxt] == 0) q.push(nxt);
        }
    }

    for(int i = 1; i<=n; i++) if(isbase[i]) cout<< i << " " << cnt[i] << "\n";
    return 0;
}
