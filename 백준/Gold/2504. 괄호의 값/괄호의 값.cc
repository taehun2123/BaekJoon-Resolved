#include <bits/stdc++.h>
using namespace std;

stack<char> listchar;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;
    int temp = 1;
    int sum = 0;
    for(int i = 0; i<input.length(); i++) {
        if(input[i] == '(') {
            temp *= 2;
            listchar.push('(');
        }
        else if (input[i] == '[') {
            temp *= 3;
            listchar.push('[');
        }
        else if (input[i] == ')') {
            if (listchar.empty() || listchar.top() != '(') {
                sum = 0;
                break;
            }
            if (input[i - 1] == '(') {
                sum += temp;
                temp /= 2;
                listchar.pop();
            } else {
                temp /= 2;
                listchar.pop();
            }
        }
        else if (input[i] == ']') {
            if (listchar.empty() || listchar.top() != '[') {
                sum = 0;
                break;
            }
            if (input[i - 1] == '[') {
                sum += temp;
                temp /= 3;
                listchar.pop();
            } else {
                temp /= 3;
                listchar.pop();
            }
        }
    }

    if(!listchar.empty()) {
        sum = 0;
    }
    cout << sum;


    return 0;
}
