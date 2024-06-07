#include <bits/stdc++.h>
using namespace std;

bool isBalanced(const string& input) {
    stack<char> s;
    for(char c : input) {
        if(c == '(') {
            s.push(c);
        } else if(c == ')') {
            if(s.empty() || s.top() != '(') {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string input;
        cin >> input;
        if(isBalanced(input)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}
