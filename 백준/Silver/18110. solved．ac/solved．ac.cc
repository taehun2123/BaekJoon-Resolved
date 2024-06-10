#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int canceled = round(n * 0.15);
    int sum = 0;
    for(int i = canceled; i < n - canceled; i++){
        sum += arr[i];
    }

    int count = n - 2 * canceled;
    if(count > 0) {
        cout << round(static_cast<double>(sum) / count);
    } else {
        cout << 0;
    }

    return 0;
}
