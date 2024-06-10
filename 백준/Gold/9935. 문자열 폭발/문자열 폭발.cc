#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    string word,boom;
    cin >> word >> boom;

    stack<char> s;

    string ans;
    for(int i = 0; i < word.length(); i++){
        s.push(word[i]);
        if(word[i] == boom[boom.length()-1] && s.size() >= boom.length()){
            string tmp;
            for(int j = 0; j < boom.length(); j++){
                tmp.push_back(s.top());
                s.pop();
            }
            reverse(tmp.begin(),tmp.end());

            if(tmp.compare(boom) != 0){
                for(int i = 0; i < tmp.length(); i++)
                    s.push(tmp[i]);
            }
        }
    }

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(),ans.end());
    if(ans.empty())
        cout << "FRULA";
    else
        cout << ans;
}