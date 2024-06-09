#include <bits/stdc++.h>
using namespace std;
deque<int> dq;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--){
        string command;
        int push_num;
        cin >> command;
        if(command == "push_front"){
            cin >> push_num;
            dq.push_front(push_num);
        }
        if(command == "push_back"){
            cin >> push_num;
            dq.push_back(push_num);
        }
        if(command == "pop_front"){
            if(dq.empty())
                cout << -1 << "\n";
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        if(command == "pop_back"){
            if(dq.empty())
                cout << -1 << "\n";
            else{
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        if(command == "size"){
            cout << dq.size() << "\n" ;
        }
        if(command == "empty"){
            cout << dq.empty() << "\n";
        }
        if(command == "front"){
            if(dq.empty())
                cout << -1 << "\n";
            else
            cout << dq.front() << "\n";
        }
        if(command == "back"){
            if(dq.empty())
                cout << -1 << "\n";
            else
            cout << dq.back() << "\n";
        }
    }
    return 0;
}
