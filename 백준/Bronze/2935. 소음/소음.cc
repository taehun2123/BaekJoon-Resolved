#include <bits/stdc++.h>
using namespace std;
string addStrings(const string& num1, const string& num2) {
    int len1 = num1.size();
    int len2 = num2.size();

    if (len1 > len2) {
        return '1' + string(len1 - len2 - 1, '0') + num2;
    } else if (len2 > len1) {
        return '1' + string(len2 - len1 - 1, '0') + num1;
    } else { // 같은 경우 자릿 수만 덧셈
        return '2' + string(len1 - 1, '0');
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a,b;
    char del;
    cin >> a >> del >> b;
    if(del == '+'){
        cout << addStrings(a, b);
    } else {
        for(auto i: a){
            if(i == '0'){
                b += i;
            }
        }
        cout << b;
    }
}
