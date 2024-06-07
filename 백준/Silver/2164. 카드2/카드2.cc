#include <bits/stdc++.h>
using namespace std;
queue<int> queStack;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i =1; i<=n; i++){
        queStack.push(i);
    }
    int i = 1;
    while(queStack.size() != 1){
        if(i%2 == 0){
            int temp = queStack.front();
            queStack.pop();
            queStack.push(temp);
        } else
            queStack.pop();
        i++;
    }
    cout << queStack.front();
    return 0;
}
