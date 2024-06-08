#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, cnt = 0;
    cin >> n;
    if(n==4){
        cout << -1;
        return 0;
    }
    bool flag = false;
    for(int i = 0; i<= (n/3); i++){
       for(int j = 0; j <= (n/5); j++){
           int sum = (j * 5) + (i * 3);
           if(sum == n){
               cnt = i+j;
               flag = true;
               break;
           }
       }
       if(flag) break;
    }
    if(cnt == 0){
        cout << -1;
    } else {
        cout << cnt;
    }
    return 0;
}
