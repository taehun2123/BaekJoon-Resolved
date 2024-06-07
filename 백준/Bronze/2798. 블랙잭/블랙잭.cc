#include <bits/stdc++.h>
using namespace std;
int card[101];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, max = -1;
    cin >> n >> m;
    for(int i =0;i<n; i++){
        cin >> card[i];
    }
    for(int i = 0; i<n-2;i++){
        for(int j = i+1; j<n-1; j++){
            for(int k = j+1; k<n; k++){
                if(m >= (card[i] + card[j] + card[k])){
                    int sum = card[i] + card[j] + card[k];
                    max = max > sum ? max : sum;
                }
            }
        }
    }
    cout << max;
    return 0;
}
