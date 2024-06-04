#include <bits/stdc++.h>
using namespace std;
vector<int> box;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int row;
    cin >> row;
    while(row--){
        int su;
        cin >> su;
        box.push_back(su);
    }
    sort(box.begin(), box.end());

    int row2;
    cin >> row2;
    while(row2--){
        int su;
        cin >> su;
        int found = binary_search(box.begin(), box.end(), su);
        cout << found << "\n";
    }
}
