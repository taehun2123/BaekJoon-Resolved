#include <bits/stdc++.h>
using namespace std;
int n;
int cnt;

bool isPrime(int num){
    if(num==1) return 0;
    for(int i = 2; i*i <= num; i++){
        if(num%i==0) return 0;
    }
    return 1;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    while(n--){
        int sn;
        cin >> sn;
        isPrime(sn) && cnt++;
    }

    cout << cnt;
    return 0;
}
