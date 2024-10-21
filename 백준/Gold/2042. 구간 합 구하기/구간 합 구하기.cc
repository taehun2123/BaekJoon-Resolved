#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll N, M, K;
ll arr[1000005];
ll segTree[4*1000005];


//재귀함수의 초기화
ll init(int node, int st, int end){
    if(st == end) return segTree[node] = arr[st];
    int mid = (st+end) /2;
    return segTree[node] = init(node*2, st, mid) + init(node*2+1, mid+1, end);
}

//void update(int node, int st, int end, int idx, ll val){
//    if (st == end) {
//        segTree[node] += val;
//        return;
//    }
//
//    int mid = (st + end) / 2;
//    if (idx <= mid) {
//        update(2*node, st, mid, idx, val);
//    } else {
//        update(2*node+1, mid+1, end, idx, val);
//    }
//    segTree[node] = segTree[2*node] + segTree[2*node+1];
//}
void update(int node, int st, int end, int idx, ll val){
    if (st == end) {
        segTree[node] = val;  // 직접 값을 변경
        return;
    }

    int mid = (st + end) / 2;
    if (idx <= mid) {
        update(2*node, st, mid, idx, val);
    } else {
        update(2*node+1, mid+1, end, idx, val);
    }
    segTree[node] = segTree[2*node] + segTree[2*node+1];
}

ll sum(int left, int right, int node, int st, int end){
    if(left<=st && end <=right) return segTree[node];
    if(right < st || end < left) return 0;
    int mid = (st+end)/2;
    return sum(left, right, node*2, st, mid) + sum(left, right, node*2+1, mid+1, end);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for(int i = 1; i<=N; i++) cin >> arr[i];
    init(1, 1, N);
    for(int i = 0; i<M+K; i++){
        int num, a; ll b;
        cin >> num >> a >> b;
        if(num == 1) update(1, 1, N, a, b);
        else cout << sum(a, b, 1, 1, N) << "\n";
    }
    return 0;
}
