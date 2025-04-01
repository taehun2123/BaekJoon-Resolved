#include <bits/stdc++.h>
using namespace std;
string N;
float answer;
int main() {
    ios::sync_with_stdio(0);
    cin >> N;
    if(N == "A+") answer = 4.3;
    else if(N == "A0") answer = 4.0;
    else if(N == "A-") answer = 3.7;
    else if(N == "B+") answer = 3.3;
    else if(N == "B0") answer = 3.0;
    else if(N == "B-") answer = 2.7;
    else if(N == "C+") answer = 2.3;
    else if(N == "C0") answer = 2.0;
    else if(N == "C-") answer = 1.7;
    else if(N == "D+") answer = 1.3;
    else if(N == "D0") answer = 1.0;
    else if(N == "D-") answer = 0.7;
    else answer = 0.0;

    cout << fixed << setprecision(1) << answer;
}
