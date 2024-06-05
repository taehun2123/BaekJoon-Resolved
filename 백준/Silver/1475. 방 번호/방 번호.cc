#include <bits/stdc++.h>
using namespace std;

int plastic[10];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int su;
    cin >> su;
    string s = to_string(su);
    for(auto c: s) {
        if(plastic[c-'0'] >= 1 && (c == '9' || c == '6')){
            if(c=='9'){
                if(plastic[(c-'0')-3] >= 1){
                    if(plastic[(c-'0')] == plastic[(c-'0')-3]){
                        plastic[c-'0']++;
                    } else if(plastic[c-'0'] < plastic[(c-'0')-3]) {
                        plastic[(c-'0')]++;
                    } else {
                        plastic[(c-'0')-3]++;
                    }
                }
                else
                    plastic[(c-'0')-3]++;
            } else {
                if(plastic[(c-'0')+3] >= 1){
                    if(plastic[(c-'0')] == plastic[(c-'0')+3]){
                        plastic[c-'0']++;
                    } else if(plastic[c-'0'] < plastic[(c-'0')+3]) {
                        plastic[(c-'0')]++;
                    } else{
                        plastic[(c-'0')+3]++;
                    }
                }
                else
                    plastic[(c-'0')+3]++;
            }
        } else plastic[c-'0']++;
    }
    int max = plastic[0];
    for(int i =0; i<10; i++)
        max = max < plastic[i] ? plastic[i] : max;

    cout << max;
}
