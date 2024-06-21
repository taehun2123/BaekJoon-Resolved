#include <bits/stdc++.h>
using namespace std;
int height[80001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long cnt = 0;
    cin >> n;
    stack<int> st;
    for(int i = 0; i<n; i++) {
        cin >> height[i];
        while(!st.empty() && height[st.top()] <= height[i]){
            st.pop();
        }
        cnt += st.size();
        st.push(i);
    }
    cout << cnt;
    return 0;
}
