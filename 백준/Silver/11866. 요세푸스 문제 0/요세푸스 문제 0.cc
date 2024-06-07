#include <bits/stdc++.h>
using namespace std;
list<int> pus;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto it = pus.begin();
    int n, k;
    cin >> n >> k;
    for(int i = 1; i<=n; i++){
        pus.push_back(i);
    }
    cout << "<";
    while(!pus.empty()){
        for(int i = 0; i < k; i++) {
            it++;
            if(it == pus.end()) {
                it = pus.begin();
                if(i < k)
                    continue;
                else if(i == k)
                    break;
            }
        }
        cout << *it;
        it = --pus.erase(it);
        if (!pus.empty()) {
            cout << ", ";
        }
    }
    cout << ">";
    return 0;
}
