#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int comp(const int &v1, const int &v2){
    return v1 > v2;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    while(n--){
        int score;
        cin >> score;
        arr.push_back(score);
    }
    stable_sort(arr.begin(), arr.end(), comp);
        cout << arr[(arr.size() - (arr.size()-k))-1];
}
