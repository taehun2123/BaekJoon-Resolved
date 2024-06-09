#include <bits/stdc++.h>
using namespace std;
int box[1000001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin >> x;
    box[1] = 0;
    box[2] = 1;
    box[3] = 1;
    for(int i = 4; i<=x; i++){
        box[i] = box[i-1] + 1;
        if(i%2==0) box[i] = min(box[i], box[i/2]+1);
        if(i%3==0) box[i] = min(box[i], box[i/3]+1);
    }
    cout << box[x];
    return 0;
}
