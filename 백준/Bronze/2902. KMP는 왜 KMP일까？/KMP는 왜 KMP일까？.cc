#include <bits/stdc++.h>
using namespace std;
vector<string> split(string input, char del){
    vector<string> answer;
    stringstream ss(input);
    string tmp;

    while(getline(ss, tmp, del)){
        answer.push_back(tmp);
    }
    return answer;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    vector<string> box = split(str, '-');
    for(string s : box){
        cout << s[0];
    }
}
