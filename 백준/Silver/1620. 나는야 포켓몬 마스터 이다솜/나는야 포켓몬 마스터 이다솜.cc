#include <bits/stdc++.h>
using namespace std;
map<string, int> pokeString;
string pokeInt[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> pokeInt[i];
        pokeString[pokeInt[i]] = i;
    }
    while(m--){
        string ques;
        cin >> ques;
        if(ques[0]-'0' >= 0 && ques[0]-'0' <= 9){
            cout << pokeInt[stoi(ques)] << "\n";
        } else {
            cout << pokeString[ques] << "\n";
        }
    }
    return 0;
}
