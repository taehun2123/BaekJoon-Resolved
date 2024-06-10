#include <bits/stdc++.h>
using namespace std;
stack<pair<int,char>> listing;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string input;
    cin >> input;
    for(auto ch : input){
        if (ch == '+' || ch == '-') {
            while(!listing.empty() && listing.top().first >= 1){
                cout << listing.top().second;
                listing.pop();
            }
            listing.emplace(1, ch);
        }
        else if(ch == '*' || ch == '/'){
            while(!listing.empty() && listing.top().first >= 2){
                cout << listing.top().second;
                listing.pop();
            }
            listing.emplace(2,ch);
        }
        else if(ch == '('){
            listing.emplace(0,ch);
        }
        else if(ch == ')'){
            while(!listing.empty() && listing.top().first != 0){
                cout << listing.top().second;
                listing.pop();
            }
            if (!listing.empty() && listing.top().first == 0) {
                listing.pop();
            }
        } else if(isalpha(ch)) {
            cout << ch;
        }
    }
    while(!listing.empty()){
        cout << listing.top().second;
        listing.pop();
    }
    return 0;
}
