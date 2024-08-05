#include <bits/stdc++.h>
using namespace std;
int n,r,q;
int board[100002];
bool vis[100002];
vector<int> v[100002];
void makeTree(int node, int parents){
    vis[node] = 1;
    for(int i = 0; i<v[node].size(); i++){
        int next = v[node][i];
        if(vis[next]) continue;
        makeTree(next, node);
    }
    if(parents != -1) board[parents] += board[node]; //서브 트리의 정점의 노드들을 계산
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(board, board+100002, 1);
    cin >> n >> r >> q;
    for(int i = 0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    makeTree(r, -1); // r을 루트로 하는 트리

    for(int i = 0; i<q; i++){
        int q;
        cin >> q;
        cout << board[q] << "\n";
    }


    return 0;
}
