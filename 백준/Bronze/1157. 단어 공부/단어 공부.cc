#include <bits/stdc++.h>
using namespace std;
#define MINIMUM (-123456789)
int alp[27];
string input;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> input;
    for(auto a : input){
        ++alp[(int)((tolower(a))-'a')];
    }

    int maxElement = 0;
    for(int i = 0; i<26; i++){
        maxElement = max(maxElement, alp[i]);
    }

    int maxCount = 0;
    int maxIdx = 0;
    for(int i = 0; i < 26; i++){
        if(maxElement == alp[i]){
            maxCount++;
            maxIdx = i;
        }
    }

    if(maxCount > 1) cout << "?";
    else {
        char maxAlpha = (char)(maxIdx+65);
        cout << maxAlpha;
    }




    return 0;
}
