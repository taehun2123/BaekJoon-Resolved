#include <bits/stdc++.h>
using namespace std;
queue<int> sb;
void pushStack(string command, int num){
    if(command == "push"){
        sb.push(num);
    }
}
void handleStack(string command){
    if(command == "pop"){
        if(sb.empty()){
            cout << -1 << "\n";
        } else {
            cout << sb.front() << "\n";
            sb.pop();
        }
    }
    if(command == "size"){
        cout << sb.size() << "\n";
    }
    if(command == "empty"){
        cout << sb.empty() << "\n";
    }
    if(command == "front"){
        if(sb.empty()) {
            cout << -1 << "\n";
        } else{
            cout << sb.front() << "\n";
        }
    }
    if(command == "back"){
        if(sb.empty()) {
            cout << -1 << "\n";
        } else{
            cout << sb.back() << "\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        string command;
        int num;
        cin >> command;
        if(command == "push") {
            cin >> num;
            pushStack(command, num);
        }
        handleStack(command);
    }
}
