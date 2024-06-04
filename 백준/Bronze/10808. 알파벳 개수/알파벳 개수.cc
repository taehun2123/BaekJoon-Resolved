#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int arr[26] = {0};
    for(char i : s){
        int ascii = i - 'a';
        arr[ascii] += 1;
    }
    for(int e : arr)
        cout << e << ' ';
    return 0;
}
