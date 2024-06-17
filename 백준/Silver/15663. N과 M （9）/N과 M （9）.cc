#include <bits/stdc++.h>
using namespace std;

int arr[10];
int init[10];
bool isUsed[10];
int n, m;

void solved(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++) {
        if(!isUsed[i] && (i == 0 || init[i] != init[i - 1] || isUsed[i - 1])) {
            arr[k] = init[i];
            isUsed[i] = true;
            solved(k + 1);
            isUsed[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> init[i];
    }

    sort(init, init + n);

    solved(0);
    return 0;
}
