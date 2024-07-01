#include <bits/stdc++.h>
using namespace std;
int n;
int s[10]; //내구도
int w[10]; //무게
int mx, cnt;

void broken(int k){
    if(k == n){
        mx = max(mx, cnt);
        return;
    }
    if(s[k] <= 0 || cnt == n-1){
        broken(k+1);
        return;
    }
    for(int i = 0; i<n; i++){
        if(i == k || s[i] <= 0) continue;
        s[k] -= w[i];
        s[i] -= w[k];
        if(s[k] <= 0) cnt++;
        if(s[i] <= 0) cnt++;
        broken(k+1);
        if(s[k] <= 0) cnt--;
        if(s[i] <= 0) cnt--;
        s[k] += w[i];
        s[i] += w[k];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> s[i] >> w[i];
    }

    broken(0);
    cout << mx;
    return 0;
}
