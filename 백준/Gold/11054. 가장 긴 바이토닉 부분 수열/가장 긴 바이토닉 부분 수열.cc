#include <bits/stdc++.h>

using namespace std;

vector<int> LIS(const vector<int>& arr) {
    vector<int> lis(arr.size(), 1);
    for (int i = 1; i < arr.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }
    return lis;
}

vector<int> LDS(const vector<int>& arr) {
    vector<int> lds(arr.size(), 1);
    for (int i = arr.size() - 2; i >= 0; --i) {
        for (int j = arr.size() - 1; j > i; --j) {
            if (arr[i] > arr[j] && lds[i] < lds[j] + 1) {
                lds[i] = lds[j] + 1;
            }
        }
    }
    return lds;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    vector<int> lis = LIS(arr);
    vector<int> lds = LDS(arr);

    int maxLength = 0;
    for (int i = 0; i < N; ++i) {
        maxLength = max(maxLength, lis[i] + lds[i] - 1);
    }

    cout << maxLength << "\n";

    return 0;
}
