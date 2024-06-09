#include <bits/stdc++.h>
using namespace std;
bool isBalanced(const string & input){
    stack<char> list;
    for(auto c:input){
        if(c == '(' || c == '['){
            list.push(c);
        }
        else if(c == ')'){
            if(list.empty() || list.top() != '(')
                return false;
            list.pop();
        }
        else if(c == ']'){
            if(list.empty() || list.top() != '[')
                return false;
            list.pop();
        }
    }
    return list.empty();
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        string input;
        getline(cin, input);
        if(input == ".") break;
        if(isBalanced(input))
            cout << "yes" << "\n";
        else
            cout << "no" << "\n";
    }
    return 0;
}
