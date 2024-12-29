#include <bits/stdc++.h>
using namespace std;
int cnt;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string word, splWord;
    getline(cin, word);
    getline(cin, splWord);
    int foundIdx = word.find(splWord); // 단어 splWord가 등장하는 최초 위치를 반환 ==> 0
    while(foundIdx != -1){
        cnt ++;
        foundIdx = word.find(splWord, foundIdx + splWord.size()); // 구분자 단어의 사이즈를 더해 중복되지 않게
    }
    cout << cnt;
    return 0;
}
