#include <bits/stdc++.h>
using namespace std;
int arr[10];
int init[10];
bool isUsed[10];
int n, m;
void solved(int k){
    if(k == m){
        for(int i = 0; i<m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int i = 0;
    while(init[i] != 0){
            arr[k] = init[i];
            solved(k+1);
        i++;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<n; i++){
       cin >> init[i];
    }
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            if(init[i] > init[j]){
                int temp = init[i];
                init[i] = init[j];
                init[j] = temp;
            }
        }
    }
    solved(0);
    return 0;
}
