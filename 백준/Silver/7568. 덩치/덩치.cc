#include <bits/stdc++.h>
using namespace std;
int height[51];
int weight[51];
int ranked[51];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> weight[i] >> height[i];
    }
    for(int i =0;i<n;i++){
        ranked[i] = 1;
        for(int j=0; j<n; j++){
            if(weight[i] < weight[j] && height[i] < height[j]){
                ranked[i] += 1;
            }
        }
    }
    for(int i = 0; i<n; i++){
        cout << ranked[i] << " ";
    }
    return 0;
}
