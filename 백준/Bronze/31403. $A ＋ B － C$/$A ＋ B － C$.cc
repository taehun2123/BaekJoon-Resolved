#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << a+b-c << "\n";
    string sa = to_string(a);
    string sb = to_string(b);
    cout << stoi(sa+sb)-c <<"\n";
}