#include <bits/stdc++.h>
using namespace std;
deque<int> queStack;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i =1; i<=n; i++){
        queStack.push_back(i);
    }
    while(queStack.size() != 1){
        cout << queStack.front() << ' ';
        queStack.pop_front();
        int temp = queStack.front();
        queStack.pop_front();
        queStack.push_back(temp);
    }
    cout << queStack.front() << ' ';
    return 0;
}
