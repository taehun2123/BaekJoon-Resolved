#include <bits/stdc++.h>
using namespace std;
int n, k;
list<int> link;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    for(int i = 1; i<=n; i++){
        link.push_back(i);
    }
    auto t = link.begin();
    cout << "<";
    while(!link.empty()){
       for(int i = 0; i<k-1; i++){
           if(*t == link.back()){
               t = link.begin();
           }
           else t++;
       }
       if(link.size() == 1){
           cout << *t;
       } else {
           cout << *t << ", ";
       }
        t = link.erase(t);
       if(t == link.end()){
           t = link.begin();
       }
    }
    cout << ">";

    return 0;
}
