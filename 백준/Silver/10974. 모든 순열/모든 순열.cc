#include <bits/stdc++.h>
using namespace std;
int n;
int arr[10];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i<=n ; i++){
        arr[i-1] = i;
    }

    do{
        for(int i = 0; i<n; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    } while(next_permutation(arr, arr+n));
    return 0;
}
