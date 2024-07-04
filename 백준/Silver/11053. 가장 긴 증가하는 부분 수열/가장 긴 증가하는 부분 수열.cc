#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1002];
int d[1002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        d[i] = 1;
    }

    for(int i = 0; i<n; i++)
        for(int j = i+1; j<n; j++)
            if(arr[i] < arr[j]) d[j] = max(d[i]+1, d[j]);

    cout << *max_element(d, d+n);

    return 0;
}
