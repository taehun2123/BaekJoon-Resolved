#include <bits/stdc++.h>
using namespace std;
list<char> editor;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string prevString;
    cin >> prevString;
    for (auto ch : prevString) {
        editor.push_back(ch);
    }

    auto it = editor.end();
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        char command;
        cin >> command;

        if (command == 'P') {
            char inCom;
            cin >> inCom;
            editor.insert(it, inCom);
        } else if (command == 'L') {
            if (it != editor.begin()) {
                --it;
            }
        } else if (command == 'D') {
            if (it != editor.end()) {
                ++it;
            }
        } else if (command == 'B') {
            if (it != editor.begin()) {
                it = editor.erase(--it);
            }
        }
    }

    for (auto e : editor) {
        cout << e;
    }

    return 0;
}
