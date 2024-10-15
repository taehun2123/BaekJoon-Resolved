#include <bits/stdc++.h>
using namespace std;
int N, K, cnt;
int arr[11];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i = 0; i<N; i++)cin >> arr[i];
    for(int i = N-1; i>=0; i--){
        if(K % arr[i] == 0){
            cnt += K/arr[i];
            K%=arr[i];
            break;
        }
        if(K % arr[i] != K) {
            cnt += K / arr[i];
            K%=arr[i];
        }
    }

    cout << cnt;

    return 0;
}
