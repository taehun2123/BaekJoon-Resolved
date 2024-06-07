#include <bits/stdc++.h>
using namespace std;

map<int, int> cardCount;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;

    while (n--) {
        int card;
        cin >> card;
        cardCount[card]++;
    }

    cin >> m;
    vector<int> results(m);
    for (int i = 0; i < m; i++) {
        int query;
        cin >> query;
        results[i] = cardCount[query];
    }

    for (int result : results) {
        cout << result << " ";
    }

    return 0;
}
