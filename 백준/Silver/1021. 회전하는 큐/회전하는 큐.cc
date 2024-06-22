#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    deque<int> dq;
    for(int i = 1; i<=n; i++){
        dq.push_back(i);
    }
    while(m--){
        int a;
        cin >> a;
        long long idx = find(dq.begin(), dq.end(), a) - dq.begin();
        while(dq.front() != a){
            if(idx < dq.size() - idx){ // 앞쪽에 가깝게 있음
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else { // 뒤쪽에 가깝게 있음
                dq.push_front(dq.back());
                dq.pop_back();
            }
            cnt++;
        }
        dq.pop_front();
    }
    cout << cnt;
    return 0;
}
