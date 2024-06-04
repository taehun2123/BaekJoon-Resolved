#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int num = 2;
    arr[0] = 1;
    arr[1] = 1;
    cin >> n >> m;
    while(num <= m){ // 모든 제곱수는 소수에서 제외하기
        for(int i = 2; i*num <= m; i++)
                arr[num*i] = 1;
        num++;
    }
    for(int i = n; i<= m; i++)
            if(!arr[i]) cout << i << "\n";
}
