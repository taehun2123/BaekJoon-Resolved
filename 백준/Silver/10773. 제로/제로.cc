#include <bits/stdc++.h>
using namespace std;
stack<int> st;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    for(int i = 0; i<k; i++){
        int a;
        cin >> a;
        if(!st.empty() && a == 0){
            st.pop();
        } else {
            st.push(a);
        }
    }
    long long sum = 0;
    while(!st.empty()){
        sum += st.top();
        st.pop();
    }
    cout << sum;

    return 0;
}
