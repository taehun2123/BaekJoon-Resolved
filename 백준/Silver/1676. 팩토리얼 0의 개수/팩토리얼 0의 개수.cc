#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    /**
     * N!에서 0의 개수를 구한다는 것은 10의 거듭제곱수를 구한다는 뜻.
     * 즉 10을 소인수 분해하여 2와 5가 들어 있는 개수 중 최솟값을 파악하면 됨.
     * 10^{min(a,b)} * 2^{c} * 5^{d} - 2와 5의 개수 중 최솟값.
     * 상대적으로 5는 항상 2보다 최솟값을 가지므로, N에서 5를 나눈 수가 최솟값이다.
     */
    int n, cnt = 0;
    cin >> n;
    for(int i = 5; i<=n; i*=5){
        cnt += n/i;
    }
    cout << cnt;
    return 0;
}
