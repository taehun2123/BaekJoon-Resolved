#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
pii li[100002];
int ans, t;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i<n; i++) cin >> li[i].second >> li[i].first; // second : 회의가 시작되는 시간, first : 끝나는 시간
    sort(li, li+n);
    for(int i = 0; i<n; i++){
        //t = 이전의 회의가 끝나는 시간
        if(t > li[i].second) continue;
        ans++;
        t = li[i].first; //회의가 끝나는 시간을 t로 재설정
    }

    cout << ans;
    return 0;
}
