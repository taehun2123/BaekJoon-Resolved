#include <bits/stdc++.h>
using namespace std;
int state[20];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int M;
    cin >> M;
    for(int i = 0; i<M; i++){
        string command;
        int X;
        cin >> command;
        if(command == "add"){
            cin >> X;
            state[X-1] = 1;
        } else if(command == "remove"){
            cin >> X;
            state[X-1] = 0;
        } else if(command == "check"){
            cin >> X;
            cout << state[X-1] << "\n";
        } else if (command == "toggle"){
            cin >> X;
            state[X-1] = 1 ^ state[X-1];
        } else if(command == "all"){
            fill(state, state+20, 1);
        } else {
            fill(state, state+20, 0);
        }
    }
    return 0;
}
