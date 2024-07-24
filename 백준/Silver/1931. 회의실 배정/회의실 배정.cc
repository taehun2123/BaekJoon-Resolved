#include <bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;
pii st[100002];
int ans, t;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> st[i].Y >> st[i].X;
    }
    sort(st, st+n); //끝나는 시간이 빠른 순 - 같다면, 시작하는 시간이 빠른 순으로 정렬
    for(int i = 0; i<n; i++){
        if(t > st[i].Y) continue; //이전 타임의 끝나는 시간이 현재의 시작하는 시간보다 더 크면 continue
        ans++;
        t = st[i].X;
    }

    cout << ans;
    return 0;
}
