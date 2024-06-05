#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int sum = 0 ;
    for(int i = 0; i<5; i++){
        int su;
        cin >> su;
        sum += su;
        arr.push_back(su);
    }
    cout << sum/5 << "\n";
    sort(arr.begin(), arr.end());
    cout << arr[arr.size()/2];
}
