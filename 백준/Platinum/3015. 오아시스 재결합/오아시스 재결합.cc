#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long ans = 0; //모든 쌍의 개수
    cin >> n;
    stack<pair<int,int>> st;
    for(int i = 0; i<n; i++) {
        int h;
        cin >> h;
        int cnt = 1; /* h가 볼 수 있는 사람 수*/
        while(!st.empty() && st.top().first <= h){ /* 만약 현재 h가 이전의 h보다 크거나 같으면 */
            ans += st.top().second; /* 그 다음으로 볼 수 있는 사람이 없으므로 ans에 추가 */
            if(st.top().first == h) cnt += st.top().second; /* 만약 현재 h와 이전 h가 같으면, 이전 h에게서 볼 수 있는 사람 수를 더함(이어받음) */
            st.pop(); /* 이전 사람 것 삭제 */
        }
        if(!st.empty()) //만약 비어있지 않다면 새로 들어온 h가 이전에 있던 h보다 작다는 것이므로 쌍 개수 1 추가
            ans++;
        st.emplace(h, cnt);
    }
    cout << ans;
    return 0;
}
/*
- 테스트 케이스
 1. 2 - poped
 2. 4 - 이전의 h보다 큼 -> ans+= cnt; 현재 ans = 2;
 3. 1 - 이전의 h보다 작으므로 ans++; 현재 ans = 3;
 4. 2 - 이전의 h보다 큼 -> ans += cnt; 현재 ans = 4; 또 스택이 비어있지 않음(4) - ans++; ans=5;
 5. 2 - 이전의 h보다 같음 -> cnt = 2; 비어있지 않으므로 ans++ ; ans = 6;
 6. 5 - 이전의 h보다 큼 -> ans += 2; ans = 8; 한번 더 돌림(4꺼) ans += 1; ans = 9;
 7. 1 - 이전 h보다 작으므로 ans++; ans = 10;
 종료,
 */