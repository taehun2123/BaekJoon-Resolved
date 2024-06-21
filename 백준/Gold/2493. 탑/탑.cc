#include <bits/stdc++.h>
using namespace std;
int height[500001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    stack<int> st;
    for(int i = 0; i<n; i++) {
        cin >> height[i];
        while(!st.empty() && height[st.top()] < height[i]) {
            st.pop();
        }
        if(st.empty()){
            cout << 0 << " ";
        }
        else {
            cout << st.top()+1 << " ";
        }
        st.push(i);
    }
    return 0;
}
